/* C++11 and follow having 'final' keyword.

   Question: How to stop someone inheriting from your class?
   Answer  : use final keyword, don't use any other tweak to achieve that, just use final keyword.
*/

#include <iostream>
using namespace std;

//class Base {
class Base final {
    int b_var;
  public:
    Base() {}
    Base(int var):b_var(var) {}
};

// error: cannot derive from ‘final’ base ‘Base’ in derived type ‘Derived’
// to make it work remove final so anybody can derived.

class Derived: public Base {
    int d_var;
  public: 
    Derived() {}
    Derived(int a, int b):Base(a), d_var(b) {}
};

int main() {
  Derived d(1, 2);
  return 0;
}
