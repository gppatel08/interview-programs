#include <iostream>

using namespace std;

class Int {
    int _val;
  public:
    Int() {}
    Int(int val):_val(val) {}
    void printValue() { cout << "Value: " << _val << endl; }

    Int& operator++() { //pre Increment
      _val++;
      return *this;
    }

    Int operator++(int dummy) { // post Increment
      Int tmp = *this;
      ++(*this);
      return tmp;
    }
};

int main() {
  Int obj1(100);
  (obj1++).printValue(); // post increment
  obj1.printValue();
 
  Int obj2(200);
  (++obj2).printValue(); // pre increment
  obj2.printValue();
 
  return 0;
}

/*
Value: 100
Value: 101

Value: 201
Value: 201
*/
