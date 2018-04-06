/*
  Class A has a VPTR which is not there in class B. 
  In a typical implementation of virtual functions, compiler places a VPTR with every object. 
  Compiler secretly adds some code in every constructor to this.
*/

#include <iostream>
using namespace std;

class A {
public:
    virtual void fun();
};

class B {
public:
   void fun();
};

int main() {
    int a = sizeof(A), b = sizeof(B);
    cout << "a: " << a << ", b: " << b << endl;
    if (a == b) 
      cout << "a == b" << endl;
    else if (a > b) 
      cout << "a > b" << endl;
    else 
      cout << "a < b" << endl;

    return 0;
}

/* Here WORD size is 64 bits (8 bytes), Hence vptr pointer takes 8 bytes address.
a: 8, b: 1
a > b
*/
