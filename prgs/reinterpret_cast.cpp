/*
reinterpret_cast:
 1. It can perform dangerous conversions because it can typecast any pointer to any other pointer.

Bottom Line:
------------
1. The result of reinterpret_cast cannot safely be used for anything other than being cast back to its original type.
2. we should be very carefull when using this cast.
3. if we use this type of cast then it becomes non-portable product.

*/

#include <iostream>
using namespace std;

#define REINTERPRET_CAST_2

#ifdef REINTERPRET_CAST_1
class Mango {
  public:
    void eatMango() { cout << "Eating Mango" << endl; }
};

class Banana {
  public:
    void eatBanana() { cout << "Eating Banana" << endl; }
};
#endif

#ifdef REINTERPRET_CAST_2
//it is used when you want to work with bits.
struct myStruct {
  int x;
  int y;
  char c;
  bool b;
};
#endif

int main() {
#ifdef REINTERPRET_CAST_1
  Banana *b = new Banana();
  Mango *m =  new Mango();
  
 //explicitly telling to compiler assign the address of mango m to the banana address, which is dangerous
  Banana *newBanana = reinterpret_cast<Banana*>(m);
  newBanana->eatBanana();
#endif

#ifdef REINTERPRET_CAST_2
  //it is used when you want to work with bits.
  myStruct m;
  m.x = 6; m.y = 10; m.c = 'a'; m.b = true;
  
  // m ---> |x|x|x|x|y|y|y|y|c|b|-|-|    -> 4 byte word size so m structre size will be 12 bytes.
  //         0 1 2 3 4 5 6 7 8 9...11
  int *p = reinterpret_cast<int*>(&m);
  //since integer pointer so will print X value as x is integer type |x|x|x|x|
  cout << "point to x: " << *p << endl;  
  p++; // since it is a integer pointer   |y|y|y|y|
  cout << "Point to y: " << *p << endl;  // it will point to y as y is integer data
  p++;  // |c|b|-|-|
  cout << "Point to c+b: " << *p << endl;  // it will point to y as y is integer data

  char *c = reinterpret_cast<char*>(p);
  cout << "Point to c: " << *c << endl;
  
  ++c;
  bool *b = reinterpret_cast<bool*>(c);
  cout << "Point to b: " << *b << endl;
  
#endif

  return 0;
}


