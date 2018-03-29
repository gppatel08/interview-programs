/*
Question: what is structural padding and packing in C & C++?
Answer: It is a way to speed up CPU optimization. padding will give boost ur program.
*/

#include <iostream>
using namespace std;

//#pragma pack(1) //disable padding

struct Base {
  char a;
  char b;
  int i;
  char c;
};

/* 
 1. one word is 4 bytes in 32 bit processor
 2. one word is 8 bytes in 64 bit processor
*/

int main() {
  cout << "Base size: " << sizeof(Base) << endl;
  return 0;
}

/* Case I:

struct Base {
  char a;
  char b;
  int i;
};

|a|b|-|-|i|i|i|i|
 0 1 2 3 4 5 6 7

*/

/* Case II:

struct Base {
  char a;
  int i;
  char b;
};

|a|-|-|-|i|i|i|i|b|-|-|-|
 0 1 2 3 4 5 6 7 8.....11

*/

/*
How dat gets memory slots:
--------------------------
  1. 1 Byte --> can be stored at multiple of 1 memory slot
  2. 2 Byte --> can be stored at multiple of 2 memory slot
  3. 4 Byte --> can be stored at multiple of 4 memory slot
  4. 8 Byte --> can be stored at multiple of 8 memory slot
  
*/


