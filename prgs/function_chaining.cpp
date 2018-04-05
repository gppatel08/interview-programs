/*
Question: What is function chaining in C++?
Answer  : it gives good code analysis power.
*/

#include <iostream>
using  namespace std;
//#define CASE_I 1
#define CASE_II 2

class Base {
    int _a, _b;
  public: 
    /* alwys return the reference otherwise it will return the copy of the object.
       which means returning and return object is NOT the same object. */
    
#ifdef CASE_I
    Base setA(int a) { _a = a; return *this; }
    Base setB(int b) { _b = b; return *this; }
#endif

#ifdef CASE_II
    Base& setA(int a) { _a = a; return *this; }
    Base& setB(int b) { _b = b; return *this; }
#endif

    void print() { cout << "a = " << _a << ", b = " << _b << endl; }
};

int main() {
  Base b;

  b.setA(10).setB(20).print(); 
  b.print();

  return 0;
}

/*
CASE I: In case of non-reference retrun, copy of the object returned hence 
        return object will be having different address from the returning object.
        b.setA(10) -- > wil return copy of object, so if we set setB(20) from the
        copy of object it will only set 20 to the returned copy of object, Not with
        the object b. thats why object b will get set variable _a and NOT _b.
$ ./m
a = 10, b = 20
a = 10, b = 0

CASE II: In case of referce return it wil work on the original object.
         so both _a and _b get reflected in the object b.
$ ./m
a = 10, b = 20
a = 10, b = 20

*/
