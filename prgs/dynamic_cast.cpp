/*
dynamic_cast in C++
SYNTAX: dynamic_cast < new_type > (expression)

1. dynamic_cast is used at runtime to find out the correct down-cast.

NOTE: a. Need atleast one virtual function in base class.
      b. If the cast is successful, dynamic_cast returns a value of type new_type.
      c. If the cast fails and new_type is a pointer type, it returns a null pointer of that type.
      d. If the cast fails and new_type is a reference type, it throws an expection that matches a handler of type std::bad_cast.

NOTE: if we remove the virtual keyword from the Base class function declaration, we will get below error:
      error: cannot dynamic_cast 'bp' (of type 'class Base*') to type 'calss Derived1*'

Bottom Line:
------------
1. Work only on polymorphic base class (at least one virtual function in base class)
   because it uses this information to decide about wrong down-cast.
2. it is used for up-cast (D->B) and down-cast(B->D), but it is mainly used for correct downcast.
3. Using this cast has run time overhead, because it checks objects type at run time using RTTI(Run Time Type Information).
4. If we are sure that we will never cast to wrong object then we should always avoid this castans use static cast.
*/
#include <string>
#include <iostream>
#include <exception>

using namespace std;

#define REFERENCE_DYN_CAST 1
//#define POINTER_DYN_CAST 2

class Base {
  virtual void print() { cout << "Base..." << endl; }
};

class Derived1: public Base {
  void print() { cout << "Derived 1 .." << endl; }
};

class Derived2: public Base {
  void print() { cout << "Derived 2 .." << endl; }
};


int main() {
  Derived1 d1;

#ifdef POINTER_DYN_CAST
  Base *bp = dynamic_cast<Base*>(&d1); // valid code

  //Derived2 *dp2 = dynamic_cast<Derived2*>(bp); // invalid code

  // valid since cast is happening from Derived1 object to Derived1 pointer (perfect type cast)
  Derived1 *dp2 = dynamic_cast<Derived1*>(bp); 

  if(dp2 == nullptr)
    cout << "NULL" <<endl;
  else
    cout << "NOT NULL" << endl;
#endif

#ifdef REFERENCE_DYN_CAST

  try {
    Derived2 &ref = dynamic_cast<Derived2&>(d1); 
  } catch(std::exception& e) {
    cout << "-----> Reference : " << e.what() << endl;
  }
  cout << "End of main.!!" << endl;

#endif

  return 0;
}
