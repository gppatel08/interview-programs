#include <stdlib.h>

#define HEAP_OVERFLOW_1 1
//#define HEAP_OVERFLOW_2 2
//#define STACK_OVERFLOW_1 3
//#define STACK_OVERFLOW_2 4

/*
  HEAP OVERFLOW:-
  ---------------
  Heap is a region of process’s memory which is used to store dynamic variables. These variables are 
  allocated using malloc() and calloc() functions and resize using realloc() function, which are 
  inbuilt functions of C. These variables can be accessed globally and once we allocate memory on heap 
  it is our responsibility to free that memory space after use. There are two situations which can 
  result in heap overflow:
*/

#ifdef HEAP_OVERFLOW_1
/* 1. If we continuously allocate memory and we do not free that memory space after use it may result 
      in memory leakage – memory is still being used but not available for other processes. 
      C program to demonstrate heap overflow by continuously allocating memory */

#include<stdio.h>

int main() {
    for (long int i=0; i<1000000000000; i++) {
       // Allocating memory without freeing it
       int *ptr = (int *)malloc(sizeof(int));
    }
}
#endif

#ifdef HEAP_OVERFLOW_2
/* 2. If we dynamically allocate large number of variables. 
      C program to demonstrate heap overflow by allocating large memory */

#include<stdio.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int)*10000000);
}
#endif


/*
  STACK OVERFLOW:-
  ---------------
  Stack is a special region of our process’s memory which is used to store local variables used inside 
  the function, parameters passed through a function and their return addresses. Whenever a new local 
  variable is declared it is pushed onto the stack. All the variables associated with a function are 
  deleted and memory they use is freed up, after the function finishes running. The user does not have 
  any need to free up stack space manually. Stack is Last-In-First-Out data structure.

  In our computer’s memory, stack size is limited. If a program uses more memory space than the stack 
  size then stack overflow will occur and can result in a program crash. There are two cases in which 
  stack overflow can occur: */

#ifdef STACK_OVERFLOW_1
  /* 1. If we declare large number of local variables or declare an array or matrix or any higher 
        dimensional array of large size can result in overflow of stack.
        C program to demonstrate stack overflow by allocating a large local memory */

#include<stdio.h>
 
int main() {
 
   // Creating a matrix of size 10^5 x 10^5, which may result in stack overflow.
   int mat[100000][100000];
}

#endif

#ifdef STACK_OVERFLOW_2
  /* 2. If function recursively call itself infinite times then the stack is unable to store large 
        number of local variables used by every function call and will result in overflow of stack.
        C program to demonstrate stack overflow by creating a non-terminating recursive function. */

#include<stdio.h>
 
void fun(int x) {
    if (x == 1)
       return;
    x = 6;
    fun(x);
}
 
int main() {
   int x = 5;
   fun(x);
}
#endif
