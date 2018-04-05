#include <stdio.h>

/*
Reverse words in a given string:
    Example: Let the input string be “i like this program very much”. 
             The function should change the string to “much very program this like i”

Algorithm:
----------
  1. Reverse the individual words, we get the below string.
     "i ekil siht margorp yrev hcum"
  2. Reverse the whole string from start to end and you get the desired output.
     "much very program this like i"
*/


/* Function to reverse any sequence starting with pointer begin and 
   ending with pointer end */
void reverse(char *begin, char *end) {
  char temp;
  while(begin < end) {
    temp = *begin;
    *begin++ = *end;
    *end-- = temp;
  }
}

/* Function to reverse words */
void reverseWords(char *s) {
  char *word_begin = s;
  char *temp = s; //temp is for word boundry

  /* STEP 1: of the above algorithm */
  while(*temp) {
    temp++;

    if(*temp == '\0') {
      reverse(word_begin, temp-1);
    } else if(*temp == ' ') {
      reverse(word_begin, temp-1);
      word_begin = temp+1;
    }
  }

  /* STEP 2: of above algorithm*/
  reverse(s, temp-1);
}

/* The above code doesn’t handle the cases when the string starts with space. 
  The following version handles this specific case and doesn’t make unnecessary calls to 
  reverse function in the case of multiple space in between. 
  Time Complexity: O(n) */

void reverseWords1(char *s) {
  char *word_begin = NULL;
  char *temp = s; // temp is for word boundry

  /* STEP 2: of above algorithm*/
  while(*temp) {
    /* This condition is to make sure that string start with valid character only (not space) */
    if((word_begin == NULL) && (*temp != ' ')) {
      word_begin = temp;
    }

    if(word_begin && ((*(temp+1) == ' ') || (*(temp+1) == '\0'))) {
      reverse(word_begin, temp);
      word_begin = NULL;
    }
    temp++;
  }

  /* STEP 2: of above algorithm*/
  reverse(s, temp-1);
}

/* Driver function to test above functions */
int main() {
  char s[] = "Guru Prasad Patel";
  printf("Input : %s\n", s);
  reverseWords(s);
  //reverseWords1(s);
  printf("Output: %s\n", s);
  return 0;
}


