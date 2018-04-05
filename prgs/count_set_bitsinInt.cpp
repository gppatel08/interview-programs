/*
Question: what is good way to counter number of set bit using C/C++?

*/
#include <iostream>
using namespace std;

int main() {
  int number = 7; // 0111
  int number1 = number;
  int count = 0;

  //simple way
  while(number) {
    count = count + (number & 1);
    number = number >> 1;
  }

  cout << "count: " << count << endl;

  //Brian Kernighan's way
  for(count = 0; number1; ++count) {
    number1 = number1 & (number1-1);
  }
  cout << "count: " << count << endl;

  return 0;
}
