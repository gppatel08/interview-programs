/* why we need virtual destructor 

   There is one rule of thumb that if you have any function as virtual then 
   you should create your destructor virtual.
*/

#include <iostream>
using namespace std;

class Base {
  public:
    virtual void fun() { cout << "Base fun" << endl; }
    Base() { cout << "Base Constructor" << endl; }
    virtual ~Base() { cout << "Base Destructor" << endl; }
};

class Derived: public Base {
  public:
    virtual void fun() { cout << "Derived fun" << endl; }
    Derived() { cout << "Derived Constructor" << endl; }
    ~Derived() { cout << "Derived Destructor" << endl; }
};

int main() {
  Base *b1 = new Base();
  Base *b2 = new Derived();

  cout << endl;
  b1->fun();
  b2->fun();

  cout << endl;
  delete b1;
  delete b2;

  return 0;
}
