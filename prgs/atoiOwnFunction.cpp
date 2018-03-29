/*
atoi is a inbuilt function in c which is used to convert ascii to integer.
So if we have char str[] = "345", and we want this to come inside int data type 
we will use this function like this: int i = atoi(str);
*/

#include <iostream>

using namespace std;

int atoiOwn(char *str) {
  int res = 0;  // Initialize result
  int sign = 1; // Initialize sign as positive
  int index = 0;// Initialize indx of first digit

  // if number is negative, then update sign
  if(str[0] == '-') {
    sign = -1;
    index++;
  }

  for(;str[index] != '\0'; ++index)
    res = res * 10 + str[index] - '0';

  return sign * res;
}

int main() {
  char str[] = "-1233625";
  int val = atoiOwn(str);
  cout << "val: " << val << endl;
  return 0;
}
