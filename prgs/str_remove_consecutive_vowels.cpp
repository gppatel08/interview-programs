/*
Remove consecutive vowels from string:
--------------------------------------
Given a string s of lowercase letters, we need to remove consecutive vowels from the string

Note: Sentence should not contain two consecutive vowels ( a, e, i, o, u).

Examples:
         Input: geeks for geeks
         Output: geks for geks

         Input : your article is in queue 
         Output : yor article is in qu

Approach: 
        Iterate string using a loop and check for the repetitiveness of vowels in a given sentence 
        and in case if consecutive vowels are found then delete the vowel till coming next 
        consonant and printing the updated string.
*/

#include <iostream>
#include <stdio.h>

using namespace std;

/* Function which returns TRUE or FALSE for occurence of a vowel */
bool is_vow(char c) {
  return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
}

void removeVowels(string str) {
  printf("%c", str[0]);

  /* loop to check for each character */
  for(int i = 1; str[i]; i++) {
    if((!is_vow(str[i-1])) || (!is_vow(str[i]))) {
      printf("%c", str[i]);
    }
  }
  printf("\n");
}

int main() {
  char str[] = "geeks for geeks";
  removeVowels(str);

  return 0;
}
