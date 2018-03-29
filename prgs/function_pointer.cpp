/*

 1. what is function pointer and how to create then?
 2. calling a function using a function pointer.
 3. how to pass a function pointer as an argument.
 4. how to return a function pointer.
 5. how to use array of function pointers.
 6. where to use function pointers.

*/

/*
1. what is function pointer and how to create them?

Ans: normal pointer vaiables store the address of another variables, 
     function pointer store the address of the another function.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int add(int a, int b) {
  return a+b;
}

// 3. how to pass a function pointer as an argument.
int function_ptr_as_arg( int (*fun_ptr)(int,int), int a, int b ) {
  int c = (*fun_ptr)(a,b);
  return c;
}

int sub(int a, int b) {
  return a-b;
}

typedef int (*mathFun) (int, int);

// 4. how to return a function pointer.
int (*funTypeReturn(int type)) (int, int) { // this line is more tricky
//mathFun funTypeReturn(int type) {
  if(type == 1)
    return add;
  else if(type == 2)
    return sub;
}

// 6. where to use function pointers.
int compare(const void *p, const void *q) {
  int l = *(const int*)p;
  int r = *(const int*)q;
  return l>r;
}

int main() {
  // 1. what is function pointer and how to create then?
  int (*fun_new_sum) (int, int) = add; //new type to assign address

  int b = fun_new_sum(4,5); // 2. calling a function using a function pointer.
  cout << " B : " << b << endl;

  // 1. what is function pointer and how to create then?
  int (*fun_old_sum) (int, int) = &add; //old type to assign address

  int c = (*fun_old_sum)(2,3); // 2. calling a function using a function pointer.
  cout << " C : " << c << endl;

  // 3. how to pass a function pointer as an argument.
  int d = function_ptr_as_arg(fun_old_sum, 20, 30);
  cout << " D : " << d << endl;

  int (*mFun) (int, int);
  mFun = funTypeReturn(2); // 4. how to return a function pointer.
  int result = (*mFun)(20, 10);
  cout << " result : " << result << endl;

  // 5. how to use array of function pointers.
  mathFun arr[2] = {add, sub};
  //int (*arr[2])(int, int) = {add, sub}; //this also we can use if we dont typedef function pointer

  int x = (*arr[0])(100, 50);
  int y = (*arr[1])(100, 50);
  cout << " add : " << x << endl;
  cout << " sub : " << y << endl;

  // 6. where to use function pointers.
  int numberArray[5] = {5, 3, 8, 4, 1};
  int arraySize = sizeof(numberArray)/sizeof(numberArray[0]);
  int elementSize = sizeof(numberArray[0]);

  qsort(numberArray, arraySize, elementSize, compare);

  for(int i=0; i < arraySize; i++) {
    cout << " " << numberArray[i];
  }
  cout << endl;
}
