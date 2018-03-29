/*
Question: When should we use reference over pointer and vice versa?

REFERENCE: Use References in function parameter and return type

 1. Pass Big Objects - (take alwys as reference)
 2. To avoid object slicing
 3. To modify local variable of caller function
 4. To achieve run time polymorphism in a function
 5. Must use referncee in copy constructor parameter


POINTERS: Use pointers in algorithm and data structures like link list, tree, graph etc.
   
 Reason 1: sometime we put NULL/nullptr in node.
 Reason 2: sometime we change pointers to point some another node.
*/

#include <iostream>
using namespace std;

//#define PASS_BIG_OBJ_AS_REFERENCE 1
#define OBJ_SLICING 2

#ifdef PASS_BIG_OBJ_AS_REFERENCE
class BigClass { };

void function1(BigClass obj) { }

void function2(BigClass& obj) { }

int main() {
  BigClass obj;
  function1(obj); // in this case it will copy the whole obj data to calling function
  function2(obj); // in this case only reference of obj will be passed
  return 0;
}
#endif

#ifdef OBJ_SLICING
class Base {
    int x;
  public:
    Base(){}
    Base(const Base& b):x(b.x){}
    virtual void print() { cout << "Base" << endl;  }
};

class Derived: public Base {
    int y;
  public:
    virtual void print() { cout << "Derived" << endl;  }
    
};

void function1(Base b) { b.print(); } 

// This function will be polymorphic, Hence based on the passed object type print function will get called
// below function with reference will achive run time polymorphim
void function2(Base& b) { b.print(); } // virtual behaviour can be achived without pointer through reference(&)

int main() {
  Derived d;
  function1(d); // it has sliced out the derived part from the derived object d, Hence Base print will get called
  function2(d); // virtual behaviour is achieved through reference, Hence Derived print will get called

  Base b;
  function2(b);

  return 0;
}

#endif
