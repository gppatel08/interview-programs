/*
Copy elision in C++:
--------------------
  Copy elision (or Copy omission) is a compiler optimization technique that avoids unnecessary copying of objects. 
  Now a days, almost every compiler uses it. Let us understand it with the help of an example. */

#include <iostream>
using namespace std;
  
class B {
public:    
    B(const char* str = "\0") { //default constructor
        cout << "Constructor called" << endl;
    }    
     
    B(const B &b) { //copy constructor
        cout << "Copy constructor called" << endl;
    } 
};
  
int main() { 
    B ob = "copy me"; 
    return 0;
}

/* OUTPUT:
$g++ copyElision.cpp -o m
$./m

Constructor called

  Why copy constructor is not called?
  According to theory, when the object “ob” is being constructed, one argument constructor is used to convert “copy me” 
  to a temporary object & that temporary object is copied to the object “ob”. So the statement

     B ob = "copy me";  should be broken down by the compiler as  B ob = B("copy me");

     However, most of the C++ compilers avoid such overheads of creating a temporary object & then copying it.

  The modern compilers break down the statement B ob = "copy me"; //copy initialization as
    B ob("copy me"); //direct initialization

  and thus eliding call to copy constructor. However, if we still want to ensure that the compiler doesn’t elide the call to copy 
  constructor [disable the copy elision], we can compile the program using “-fno-elide-constructors” option with g++ and 
  see the output as following:

  $ g++ copyElision.cpp -fno-elide-constructors -o m
  $ ./m

  Constructor called
  Copy constructor called

  If “-fno-elide-constructors” option is used, first default constructor is called to create a temporary object, 
  then copy constructor is called to copy the temporary object to ob.
*/
