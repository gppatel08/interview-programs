/* Reverse a string in C/C++ (Different Methods) */

#include <iostream>
#include <algorithm>
using namespace std;

//#define REVERSE_WITH_SWAP 1
//#define REVERSE_WITH_INBUILT_REVERSE 2
//#define REVERSE_WITH_STRLEN 3
#define REVERSE_A_CONST_STRING 4


#ifdef REVERSE_WITH_SWAP
//1. Write own reverse function by swapping characters:
void reverseStr(string &str) {
  int length = str.length();

  //swap character starting from two corners
  for(int i = 0; i < length/2; i++)
    swap(str[i], str[length - 1 - i]);
}

int main() {
  string str = "Hello World!";
  reverseStr(str);
  cout << str << endl;
  return 0;
}
#endif

/* 2. Using inbuilt “reverse” function: 
      There is a direct function in “algorithm” header file for doing reverse that saves our time 
      when programming.
      
      Reverses elements in [begin, end]
           void reverse (BidirectionalIterator begin, BidirectionalIterator end);
*/

#ifdef REVERSE_WITH_INBUILT_REVERSE
int main()
{
   string str = "Guru Prasad Patel";
    
   // Reverse str[beign..end]
   reverse(str.begin(),str.end());
    
   cout << str << endl; 
   return 0;
}
#endif

/* 3. Write own reverse function with strlen(): 
      strlen is an inbuilt library function used to calculate string length. 
      need to be included to use this method.
   
      CPP program to reverse a given string using strlen() */

#ifdef REVERSE_WITH_STRLEN

#include<stdio.h>
#include<string.h>
  
// Function to reverse a string
void * reverse(char * str )
{ 
    int i, len ;
      
    // calculating length of the string
    len = strlen(str);
      
    for( i=len ; i>=0 ; i--)   // *(str+i) is the character at the ith index of the string
        printf( "%c", *(str+i));
    printf("\n");
}

// Driver code
int main( void )
{
    char a[] = "Guru Prasad Patel" ;
      
    reverse(a);
    return(0);
}
#endif

/* 4. Reverse a constant string: 
      If the string is a const string (not editable), then how do we create a string which is the 
      reverse of given string?

      We need to create an array and return the pointer of that. Let’s see how to do it:
      C Program to reverse a constant string and return the pointer of that */

#ifdef REVERSE_A_CONST_STRING
 
#include <stdio.h>
#include <string.h>
#include <malloc.h>
 
// Function to reverse string and return reverse string pointer of that
char* ReverseConstString(char *str)
{
    int start, end, len;
    char temp, *ptr = NULL;
     
    len = strlen(str);    // find length of string
     
    ptr = (char*)malloc(sizeof(char)*(len+1)); // create dynamic pointer char array
     
    ptr = strcpy(ptr,str);             // copy of string to ptr array
     
    // swapping of the characters
    for (start=0,end=len-1; start<=end; start++,end--)
    {
        temp = ptr[start];
        ptr[start] = ptr[end];         
        ptr[end] = temp;
    }
     
    return ptr; // return pointer of reversed string
}
 
// Driver Code
int main(void) 
{
    const char const *str = "GeeksforGeeks";
    printf("%s", ReverseConstString(str));
    return 0;
}
#endif
