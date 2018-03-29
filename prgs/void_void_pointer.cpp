/*
Question: what is void and void pointer(void*) in C/C++?

Topic: void
  1. void is used to denote nothing
  2. if some function is not returning anything then we use void type to denote that.
  3. if some function doesn't take any parameters then we use void to denote this.
  4. we can not create void variable.
  5. sizeof void is 1 in gcc compilers but in other it is not valid to check sizeof void.

Topic: void*
  1. void* is universal pointer
  2. we can convert any data type pointer to void* (except function pointer, const or volatile)
  3. void* can not be dereferenced
*/

#include <iostream>
using namespace std;

//#define CANT_VOID_VARIABLE 1
//#define VOID_RETURN_VOID_FUN_PARAMETER 2
//#define SIZE_OF_VOID 3
//#define VALID_CODE 4
//#define FUNCTION_PTR_TO_VOID_PTR 5
//#define CONST_DTYPE_PTR_TO_VOID_PTR 6
//#define VOLATILE_DTYPE_PTR_TO_VOID_PTR 7
#define CANT_DEREFERENCE_VOID_PTR 8
//#define VALID_CONVERSION 9

void function (void) {
  cout << "C++" << endl;
}

int main() {

#ifdef CANT_VOID_VARIABLE
  void x;  // error: variable or field 'x' declared void
#endif

#ifdef VOID_RETURN_VOID_FUN_PARAMETER
  function(); // OUTPUT: C++
#endif

#ifdef SIZE_OF_VOID
  // gcc/g++ gives -> warning: invalid application of 'sizeof' to a void type [ -Wpointer-arith ]
  /* http://rextester.com/l/cpp_online_compiler_visual --> vc++ gives below error:
                  source_file.cpp(7): error C2070: 'void': illegal sizeof operand
                  Microsoft (R) C/C++ Optimizing Compiler Version 19.00.23506 for x64 */
  cout << "sizeof(void): " << sizeof(void) << endl; // OUTPUT: sizeof(void): 1
#endif

#ifdef VALID_CODE
  int *a = new int(10);
  void *v = a; //  valid code

  void *v1 = static_cast<void*>(a); // compile time error: const data type can't be convert into void*
#endif

#ifdef FUNCTION_PTR_TO_VOID_PTR
  void *v2 = static_cast<void*>(function); // error: invalid static_cast from type 'void()' to type 'void*'
#endif

#ifdef CONST_DTYPE_PTR_TO_VOID_PTR
  const int *i = new int(10);
  void *v3 = static_cast<void*>(i); // error: invalid static_cast from type 'const int*' to type 'void*'
#endif

#ifdef VOLATILE_DTYPE_PTR_TO_VOID_PTR
  volatile int *i = new int(10);
  void *v3 = static_cast<void*>(i); 
#endif

#ifdef CANT_DEREFERENCE_VOID_PTR
  int *i = new int(10);
  void *v3 = static_cast<void*>(i); 

  cout << *v3 << endl; // error: 'void*' is not a pointer-to-object type
#endif

#ifdef VALID_CONVERSION
  int *i = new int(10);
  void *v3 = static_cast<void*>(i);
  cout << *(static_cast<int*>(v3)) << endl;
#endif

  return 0;
}


/*
Bottom Line:
------------
  1. SO only void means nothing and void* means pointer to anything(except function pointer, const or volatile)

Use Cases:
----------
  1. malloc and calloc returns void* so that we can typecast to our desired data type.
  2. void* are used to create generic function in C. (compare function used in qsort function in C).
*/
