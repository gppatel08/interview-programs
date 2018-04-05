/*
Return maximum occurring character in an input string:-
-------------------------------------------------------
  Write an efficient C function to return maximum occurring character in the input string e.g., 
  if input string is “test” then function should return ‘t’.

Algorithm:
----------
  One obvious approach to solve this problem would be to sort the input string and then traverse 
  through the sorted string to find the character which is occurring maximum number of times. 
  Let us see if we can improve on this. So we will use a technique called ‘Hashing’. 
  In this, when we traverse through the string, we would hash each character into an array of 
  ASCII characters.

Input string = “test”

1: Construct character count array from the input string.
  count['e'] = 1
  count['s'] = 1
  count['t'] = 2

2: Return the index of maximum value in count array (returns ‘t’).
   Typically, ASCII characters are 256, so we use our Hash array size as 256. But if we know that 
   our input string will have characters with value from 0 to 127 only, we can limit Hash array 
   size as 128. Similarly, based on extra info known about input string, the Hash array size can 
   be limited to 26.

*/

// C++ program to output the maximum occurring character in a string */

#include <iostream>
#include <string.h>
#define ASCII_SIZE 256
using namespace std;
 
char getMaxOccuringChar(char* str) {
  //create the array to keep the count of individual characters and initialize the array as 0
  int count[ASCII_SIZE] = {0};
  
  //construct character count array from the input string
  int len = strlen(str);
  for(int i = 0; i < len; i++)
    count[str[i]]++;

  int max = -1; // initialize max count
  char result;  // initialize result

  //Traverse through the string and manitaning the count of each character
  for(int i = 0; i < len; i++) {
    if(max < count[str[i]]) {
      max = count[str[i]];
      result = str[i];
    }
  }
  return result;
}

void charOccurenceCount(char *str) {
  //create the array to keep the count of individual characters and initialize the array as 0
  int count[ASCII_SIZE] = {0};
  int indexCount = 0;

  //construct character count array from the input string
  int len = strlen(str);
  for(int i = 0; i < len; i++) {
    count[str[i]]++;
    indexCount++;
  }

  for(int i = 0; i < indexCount; i++)
    cout << str[i] << " : " << count[str[i]] << endl;
}

// Driver program to test the above function
int main() {
    //char str[] = "sample string";
    char str[] = "GURUGURU";
    charOccurenceCount(str);
    cout << "Max occurring character is: " << getMaxOccuringChar(str) << endl;
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1) 
      Because we are using fixed space (Hash array) irrespective of input string size.

Notes:
------
  If more than one characters have the same count and that count is maximum then the function 
  returns the first character with maximum count in input string. For example if input string is 
  “test sample” then there are three characters with same and maximum count two i.e. “t”, “e” and 
  “s” but our program will result “t” because “t” comes first in input string. Similarly, the 
  output for “cbbbbccc” would be “c”.
*/
