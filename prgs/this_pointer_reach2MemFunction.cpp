/*
Question: What is this pointer in C++?
Answer  : 1. 'this' passed as hidden argument to on-static memebr functions.
          2. 'this' is a const pointer which holds the address of current object.
                         [ TYPE* const this ]
          3. If member function is 'const' then 'this' pointers type becomes 
                         [ const TYPE* const this ]

*/

#include <iostream>
using namespace std;

class Base {
    int _a;
  public:
    void setValue(int a) { _a = a; }
    // Equivalent: void setValue(Base* const this, int a) { this->_a = a; }

    int getValue() const { return _a; }
    // Equivalent: int getValue(const Base* const this) const { return this->_a; }
};

int main() {
  Base b;
  b.setValue(10);  // Equivalent : setValue(&b, 10);

  b.getValue();    // Equivalent : getValue(&b);

  return 0;
}
