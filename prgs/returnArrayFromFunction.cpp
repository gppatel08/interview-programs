#include <iostream>
using namespace std;

/*
1. One-Dimentioanl Array return from Function:
-------------------------------------------
The issue is if you return locally created array (non-static) from function then it will be run time error 
because if we create anything on function stack it will be claimed back once that function is returning back.

There are basically two ways to return an array from function. 
 1. First way is to use static array and return it form function.
 2. second way is to create array dynamically and then return it from a function.
*/

//#define ONED_DONT_RETURN_LOCAL_REF_PTR 1
//#define ONED_DECLARE_ARR_AS_STATIC 2
//#define ONED_DYNAMIC_ALLOC_ADDRESS_RETURN 3
//#define TWOD_DYNAMIC_ARRAY 4
#define TWOD_STATIC_ARRAY 5


#ifdef ONED_DONT_RETURN_LOCAL_REF_PTR
int* function() {
  int arr[3] = {1, 2, 3}; // warning: address of local variable ‘arr’ returned [-Wreturn-local-addr]
  return arr; //return pointers of local or references of loacal are NOT good idea, hence this is wrong return
}

int main() {
  int *arr = function(); 
 
  cout << arr[0] << endl;
  cout << arr[1] << endl;
  cout << arr[2] << endl;
 
  return 0;
}
/* OUTPUT:
$ ./m
Segmentation fault (core dumped)
*/
#endif


#ifdef ONED_DECLARE_ARR_AS_STATIC
int* function() {
  static int arr[3] = {1, 2, 3};
  return arr; //valid return
}

int main() {
  int *arr = function();

  cout << arr[0] << endl;
  cout << arr[1] << endl;
  cout << arr[2] << endl;

  return 0;
}
#endif

#ifdef ONED_DYNAMIC_ALLOC_ADDRESS_RETURN
int* function() {
  int* arr = new int[3]; //Memory is created in heap and base address is assigned into arr pointer variable
  
  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 3;

  return arr; 
}

int main() {
  int *arr = function();

  cout << arr[0] << endl;
  cout << arr[1] << endl;
  cout << arr[2] << endl;

  delete[] arr;

  return 0;
}
#endif

/* Two Dimentional Array return from Function:
   ===========================================
   How to return 2-D array from function in C & C++?
   Ans: 1. Using Dynamic Array
        2. Using static keyword
        3. Using struct keyword
*/

const int N = 3;

#ifdef TWOD_DYNAMIC_ARRAY
void displayArray(int** arr) {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cout << " " << arr[i][j];
    }
    cout << endl;
  }
}

int** getArrayDynamically() {
  int** arr = new int*[N];
  for(int i = 0; i < N; i++) {
    arr[i] = new int[N];
    for(int j = 0; j < N; j++) {
      arr[i][j] = i + j;
    }
  }

  return arr;
}

/*
void freeTwoDArray(int** arr) {
 for(int i = 0; i < N; i++) {
   int *a = arr[i];
   delete[] a;
 } 
 delete[][] arr;
}*/

int main() {
  int **a;
  a = getArrayDynamically();
  displayArray(a);
  //freeTwoDArray(a);

  return 0;
}
#endif

#ifdef TWOD_STATIC_ARRAY
void displayArray(int arr[][N]) {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cout << " " << arr[i][j];
    }
    cout << endl;
  }
}

//typedef (*DoublePointer123) [N];
//DoublePointer123 getArrayStatically() {
int (*(getArrayStatically)())[N] {
  static int arr[N][N] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
  return arr;
}

int main() {
  int (*arr)[N];
  arr = getArrayStatically();
  displayArray(arr);

  return 0;
}
#endif
