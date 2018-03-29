/*
const_cast in C++

The expression const_cast<T>(v) can be used to change the const or volatile qualifiers of pointers or reference.
where T must be a pointer, reference, or pointer-to-member type.


volatile is generally used in embaded system when we dont want to optimize the variables.

Bottom Line:
-----------
1. Use only when you have to.
2. Use only when the actual refered object/variable is not const.
3. Use when we are dealing with 3'rd party library and some API want dat in non-const form but we have it in const.
   (actually we can not do anything in that case, but make sure that API is not changing our variable value)
*/

#include <iostream>

using namespace std;

//#define CONST_CAST_1 1
#define CONST_CAST_2 2

#ifdef CONST_CAST_2
// 2. when we need to call some third party library where it is taking variables/object as non-const but not changing that.
void thirdPartyLibrary(int* y) {
  int k = 10;
  cout << "Value : " << k + *(y) << endl;
}
#endif

int main() {
#ifdef CONST_CAST_1
  const int a1 = 10;
  const int *b1 = &a1;
  int *d1 = const_cast<int*>(b1);
  *d1 = 15; //Invalid and Undefined behaviour!
  cout << "a1: " << a1 << endl;
  cout << "d1: " << *d1 << endl;

  int a2 = 20;  // 1. when the actual referred object/variable is not const.
  const int *b2 = &a2;
  int *d2 = const_cast<int*>(b2);
  *d2 = 30;  // Valid code!
  cout << "a2: " << a2 << endl;
  cout << "d2: " << *d2 << endl;
#endif

#ifdef CONST_CAST_2
  const int x = 20;
  const int *px = &x;
  // 2. when we need to call some third party library where it is taking variables/object as non-const but not changing that.
  //thirdPartyLibrary(const_cast<int*>(px));
  
  // error: invalid conversion from 'const int*' to 'int*' [-fpermissive]
  thirdPartyLibrary(px);
#endif

  return 0;
}
