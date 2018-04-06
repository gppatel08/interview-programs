/*
C++ default constructor | Built-in types
========================================

*/

#include <iostream>
using namespace std;
 
int main() {
 
   cout << "int(): " << int() << endl;
   return 0;
}

/*
  A constructor without any arguments or with default values for every argument, is treated as default constructor. 
  It will be called by the compiler when in need (precisely code will be generated for default constructor based on need).

  C++ allows even built-in type (primitive types) to have default constructors. 
  The function style cast int() is analogous to casting 0 to required type. The program prints 0 on console.

  The initial content of the article triggered many discussions, given below is consolidation:-
  It is worth to be cognizant of reference vs. value semantics in C++ and the concept of Plain Old Data types. 
  From Wiki, primitive types and POD types have no user-defined copy assignment operator, no user-defined destructor, 
  and no non-static data members that are not themselves PODs. Moreover, a POD class must be an aggregate, meaning it has no 
  user-declared constructors, no private nor protected non-static data, no base classes and no virtual functions.

  An excerpt (from a mail note) from the creator of C++, “I think you mix up ‘actual constructor calls’ with conceptually 
  having a constructor. Built-in types are considered to have constructors”.

  The code snippet above mentioned int() is considered to be conceptually having constructor. However, there will not be any 
  code generated to make an explicit constructor call. But when we observe assembly output, code will be generated to 
  initialize the identifier using value semantics.  */

