
/*
The idea is when you create a class and have pointer data member in that class then you should not 
rely on compiler generated copy constructor(Shallow Copy) in general, there we should implement 
our own copy constructor(Deep Copy).
*/

#include <iostream>

using namespace std;

class Base {
    int *_ptr;
    int  _val;
  public:
    Base():_ptr(new int(0)), _val(0) {}
   /* Base(const Base& b) {
      _ptr  = new int;
      *_ptr = *b._ptr;
      _val  = b._val;
    }

    ~Base() { delete _ptr; }
*/
    void setPtr(int ptr) { *_ptr = ptr; }
    void setVal(int val) { _val = val; }
    int getPtr() { return *_ptr; }
    int getVal() { return _val; }
};


int main() {
  Base b1;
  b1.setPtr(10);
  b1.setVal(20);

  //shallow copy simply copy the pointer value, hence b1 and b2's _ptr will point to same memory address
  // b2._ptr = b1._ptr
  // b2._val = b1._val
    Base b2 = b1;
    b2.setPtr(40);

  cout << "b1 ptr: " << b1.getPtr() << endl;
  cout << "b1 val: " << b1.getVal() << endl;
  cout << "b2 ptr: " << b2.getPtr() << endl;
  cout << "b2 Val: " << b2.getVal() << endl;
  return 0;
}

/*
b1 ptr: 10
b1 val: 20
b2 ptr: 40
b2 Val: 20
*/

/* if we wont provide the deep copy constructor, then output will be as below:
b1 ptr: 40
b1 val: 20
b2 ptr: 40
b2 Val: 20
*/
