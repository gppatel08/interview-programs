/*
Default Constructors:-
======================
  A constructor without any arguments or with default value for every argument, is said to be default constructor. 
  What is the significance of default constructor? Will the code be generated for every default constructor? 
  Will there be any code inserted by compiler to the user implemented default constructor behind the scenes?

  The compiler will implicitly declare default constructor if not provided by programmer, it will define it when in need. 
  Compiler defined default constructor is required to do certain initialization of class internals. 
  It will not touch the data members or plain old data types (aggregates like array, structures, etc…). 
  However, the compiler generates code for default constructor based on situation.

  Consider a class derived from another class with default constructor, or a class containing another class object with 
  default constructor. The compiler needs to insert code to call the default constructors of base class/embedded object.
*/

#include <iostream>
using namespace std;
 
class Base {
public:
    // compiler "declares" constructor
};
 
class A {
public:
    // User defined constructor
    A() {
        cout << "A Constructor" << endl;
    }
 
    // uninitialized
    int size;
};
 
class B : public A
{
    // compiler defines default constructor of B, and
    // inserts stub to call A constructor
 
    // compiler won't initialize any data of A
};
 
class C : public A
{
public:
    C()  {
        // User defined default constructor of C, and Compiler inserts stub to call A's construtor
        cout << "B Constructor" << endl;
 
        // compiler won't initialize any data of A
    }
};
 
class D
{
public:
    D() {
        // User defined default constructor of D, and a - constructor to be called, compiler inserts stub to call A constructor
        cout << "D Constructor" << endl;
 
        // compiler won't initialize any data of 'a'
    }
 
private:
    A a;
};
 
int main()
{
    Base base;
 
    B b;
    C c;
    D d;
 
    return 0;
}

/*
B b;
----
A Constructor

C c;
----
A Constructor
B Constructor

D d;
----
A Constructor
D Constructor

  There are different scenarios in which compiler needs to insert code to ensure some necessary initialization as per language 
  requirement. We will have them in upcoming posts. Our objective is to be aware of C++ internals, not to use them incorrectly.
*/
