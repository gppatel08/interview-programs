/* Q. why the size of an empy class or struct is not zero in C++ */ 

#include <iostream>

using namespace std;

class Base {};

struct Base1 {

};

/*if any member is already in class, then no need to give extra space by compiler 
to differentiate between two object  */
class Base3 {
  int _i;
};

int main() {

  /* the reason is c++ compiler make sure that two objects are different from each other
     so to make that difference you need to have base class have atleast one byte size 
     in empty class/struct case and in C/C++ smallest byte is 1 byte */ 

  cout << "size of Base : " << sizeof(Base) << endl;
  cout << "size of Base1: " << sizeof(Base1) << endl;

  Base3 b1, b2;
  cout << "size of Base3: " << sizeof(Base3) << endl;
  cout << &b1 << " :  " << &b2 << endl;

  if(&b1 == &b2)
    cout << "YES!" << endl;
  else
    cout << "NO!" << endl;
  return 0;
}
