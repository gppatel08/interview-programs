/*Q. is it possible to call constructor and destructor by yourself explicitly?
  A. we shouldn't call constructor and destructor by yourself explicitly. */

#include <iostream>

using namespace std;
#define CASE_1 1

class Base {
    int _baseVar;
  public:
    Base() { cout << "Base Constructor" << endl; }
    ~Base() { cout << "Base Destructor" << endl; }
};

int main() {
#ifdef CASE_1
  /* when you explicitly call Base constructor as below then it will call destructor immediatly */
  Base();
  /* OUTPUT:
  Base Constructor
  Base Destructor
  something
  */
  cout << "something" << endl;
#endif

#ifdef CASE_2
  Base().~Base();
  /* OUTPUT:
  Base Constructor
  Base Destructor
  Base Destructor
  */
#endif

#ifdef CASE_3
  /* its not compiler issue, its gaurenty from C++ that when object goes out of scope, 
     its destructor will get called. this is the digaster we shouldn't called explicitly.
     there is only one reason we will call destructor explicitly thats is when placement new called*/
  Base b;
  b.~Base();
  cout << "something" << endl;
  /* OUTPUT:
  Base Constructor
  Base Destructor
  something
  Base Destructor
  */
#endif

  return 0;
}
