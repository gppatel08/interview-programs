/*
Write a program to print all permutations of a given string:-
-------------------------------------------------------------
  A permutation, also called an “arrangement number” or “order,” is a rearrangement of the elements 
  of an ordered list S into a one-to-one correspondence with S itself. 
  A string of length n has n! permutation.

  Source: Mathword(http://mathworld.wolfram.com/Permutation.html)

  Below are the permutations of string ABC.
         ABC ACB BAC BCA CBA CAB

Here is a solution that is used as a basis in backtracking.
*/

// C program to print all permutations with duplicates allowed
#include <stdio.h>
#include <string.h>
 
/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int l, int r)
{
  int i;
  if(l == r)
    printf("%s\n", a);
  else {
    for(i = l; i <= r; i++) {
      swap((a+l), (a+i));
      permute(a, l+1, r);
      swap((a+l), (a+i)); // backtrack
    }
  }
}

/*
Algorithm Paradigm: Backtracking
  Time Complexity: O(n*n!) Note that there are n! permutations and 
                   it requires O(n) time to print a a permutation.

  Note : The above solution prints duplicate permutations if there are repeating characters in 
         input string. Please see below link for a solution that prints only distinct permutations 
         even if there are duplicates in input.
*/

/* Driver program to test above functions */
int main()
{
    char str[] = "ABC";
    int n = strlen(str);
    permute(str, 0, n-1);
    return 0;
}
