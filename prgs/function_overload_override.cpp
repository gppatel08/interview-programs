
#include <iostream>
using namespace std;

//#define FUNCTION_OVERLOAD 1
//#define FUNCTION_OVERRIDE_1 2
#define FUNCTION_OVERRIDE_2 3


/* 1. Function Overloading Exmple: it is called compile-time or static or early binding */

#ifdef FUNCTION_OVERLOAD
void print(int a) { cout << "Integer Fun: " << a << endl; }  // -> print01 because of name mangling smthng

void print(double a) { cout << "Double Fun: " << a << endl; } // -> print02 because of name mangling smthng

void print(char a) { cout << "Char Fun: " << a << endl; } // -> print03 because of name mangling smthng

int main() {
  // these function is bounding with the help of input parameters(arguments)
  // retrun type is not considered for function overloading
  // all print function should be in same scope for function overloading behaviour
  print(10);
  print(5.5);
  print('a');
  return 0;
}
#endif

/* Function overriding:
=======================
2. Function overriding is needed when we perform inheritence and there is a function in Base class which is
inherited into Derived but we want to provide our own definition for that derived class. in sort we dont want
to take that particular function from Base class so in that case we can write new definition for that function
in our Derived calss with same name as it is Base and this is called function overriding
*/

#ifdef FUNCTION_OVERRIDE_1
class Base {
  public:
    void print() { cout << "Base class " << endl; }
};

class Derived: public Base {
  public:
    void print() { cout << "Derived class " << endl; }
};


int main() {
  Base b;
  Derived d;

  b.print();
  d.print();

  return 0;
}

#endif

#ifdef FUNCTION_OVERRIDE_2
/* override keyword must be used w.r.t virtual keyword */

class Person {
  public:
   virtual void print() { cout << "Person" << endl; }
};

class Man: public Person {
  public:
   void print() override { cout << "Guru" << endl; }
};

class Women: public Person {
  public:
   void print() override { cout << "Deepu" << endl; } 

   //error: ‘void Women::print1()’ marked ‘override’, but does not override
   //void print1() override { cout << "Deepu" << endl; } 
};

int main() {
  Man m;
  m.print();

  Person *p = &m; // static binding
  p->print();

  return 0;
}

#endif
