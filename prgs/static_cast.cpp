/*
I have included 6 to 7 points to demonstrate the use static_cast in C++.
We use static_cast to check type casting at compile time. And it has more strict rules to check things at compile time.

1. For compatible type conversion, such as float to int.
2. For conversion operator and conversion constructors.
3. To avoid unrelated pointer conversion.
4. Avoids derived to private base class pointer conversion.
5. Use for all up cast but never use for confued down-cast because there are no runtime checks performed for static_cast conversion.
6. INtensions are more clear in C++ style cast(express you intent better and make code review easier).
7. Finding is easy.
8. Error found at compile time.
*/

#include<iostream>
#include<string> // for string class
using namespace std;

#define STATIC_CAST_5  5

#ifdef STATIC_CAST_2
//2. Use static_cast when conversion between types is provided through conversion operator or coversion constructor
class Int {
    int x;
  public:
    Int(int x=0):x(x) { cout << "conversion constructor" << endl; }
    operator string () { cout<< "coversion operator" << endl ; return to_string(x); }
};
#endif

#ifdef STATIC_CAST_4
/* 4. static_cast avoid cast from derived to private base pointer*/
class Base {};
class Derived:  private Base {};
#endif

#ifdef STATIC_CAST_5
class Base {};
class Derived1: public Base {};
class Derived2: public Base {};
#endif

int main() {

#ifdef STATIC_CAST_1
  // Q1. Why to use static_cast when implicit conversion is involved?
  // A. Because c-style cast is hard to find in code, but you can search static_cast keyword.
  float f = 3.5;
  int a;
  a = f; //hard to find in code
  a = static_cast<int>(f); //compile time conversion, search is easly
#endif

#ifdef STATIC_CAST_2
  //2. Use static_cast when conversion between types is provided through conversion operator or coversion constructor
  Int obj(3);
  cout << " step 1. " << endl;
  string str1 = obj;
  cout << " step 2. " << endl;
  obj = 20;

  cout << " step 3. " << endl;
  string str2 = static_cast<string>(obj);
  cout << " step 4. " << endl;
  obj = static_cast<Int>(30);

  /*
  conversion constructor
   step 1. 
  coversion operator
   step 2. 
  conversion constructor
   step 3. 
  coversion operator
   step 4. 
  conversion constructor
  */
#endif


#ifdef STATIC_CAST_3
  /* 3. static_cast is more restrictive than C-style
     Example: char* to  int* is allowd in C-Style but not in static_cast.
           c ->  |c|
      p = &c ->  | | | | | (p allowd to acces only 1 byte, but accessing consecutive 3 more byte, which
                            in turn do memory corrut or core segment.
  */

  char c;           // 1 byte data

  int *p = (int*)&c; // 4 byte data
  *p = 5;   // pass at compile time but fail at run time (that's why it is dangerous)

  // erroe: invalid static_cast from type 'char*' to type 'int*'
  int *ip = static_cast<int*>(&c); //FAIL : Compile time error, because not compatible type pointers.
#endif

#ifdef STATIC_CAST_4
  /* 4. static_cast avoid cast from derived to private base pointer
        erroe: 'Base' is an inaccessible base of 'Derived' */
  Derived d1;
  Base *bp1 = (Base*)&d1;  // allowd at compile time
  Base *bp2 = static_cast<Base*>(&d1); // NOT allowd at compile time
#endif

#ifdef STATIC_CAST_5
  /* use for all up cast but never use for down cast since confusing

  ->---->B<---<-
  |     / \    |
  |    /   \   |
  <----D1  D2-->

  */
  Derived1 d1;
  Derived2 d2;

  Base *bp1 = static_cast<Base*>(&d1); // Allowed (up cast)
  Base *bp2 = static_cast<Base*>(&d2); // Allowed (up cast)

  Derived1 *d1p = static_cast<Derived1*>(bp2); // Allowed, but never used like
  Derived2 *d2p = static_cast<Derived2*>(bp1); // Allowed, but never use like
#endif

#ifdef STATIC_CAST_5
  int i = 20;
  void *v = static_cast<void*>(&i);
  int *ip = static_cast<int*>(v);
  cout << "*ip : " << *ip << endl;
#endif

  return 0;
}
