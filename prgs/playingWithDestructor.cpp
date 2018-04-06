/*
  Output of the below program is “i = 3”.
  Why the output is i= 3 and not 10? 

  While returning from a function, destructor is the last method to be executed. The destructor for the object “ob” is called 
  after the value of i is copied to the return value of the function. So, before destructor could change the value of i to 10, 
  the current value of i gets copied & hence the output is i = 3.

  How to make the program to output “i = 10” ? 
  Following are two ways of returning updated value:
     1. Return by Reference:
     2. Create the object ob in a block scope
*/

#include <iostream>
using namespace std;

//#define CASE_I 1
//#define CASE_II 2
#define CASE_III 3

#ifdef CASE_I
int i;
 
class A {
public:
    ~A() { i=10; }
};
 
int foo() {
    i=3;
    A ob;
    return i;
}
 
int main() {
    cout << "i = " << foo() << endl;
    return 0;
}
#endif

#ifdef CASE_II
/* 1. Return by Reference:
      Since reference gives the l-value of the variable,by using return by reference the program will output “i = 10”. */
int i;
 
class A {
public:
    ~A() { i = 10; }
};
 
int& foo() {
    i = 3;
    A ob;
    return i;
}
 
int main() {
    cout << "i = " << foo() << endl;
    return 0;
}

/* The function foo() returns the l-value of the variable i. So, the address of i will be copied in the return value. 
   Since, the references are automatically dereferened. It will output “i = 10”.*/
#endif

#ifdef CASE_III
/* 2. Create the object ob in a block scope
      Since the object ob is created in the block scope, the destructor of the object will be called after the block ends, 
      thereby changing the value of i to 10. Finally 10 will copied to the return value. */
int i;

class A {
public:
    ~A() { i = 10; }
};

int foo() {
    i = 3;

    {
      A ob;
    }

    return i;
}

int main() {
    cout << "i = " << foo() << endl;
    return 0;
}
#endif
