#include <iostream>
using namespace std;

/* post increment(4 instructions) is more costilier then pre increment(3 instruction) */
int main() {
  int i = 10; //mov DWORD PTR [rbp-4], 10
  
  int j = 5;  // mov DWORD PTR [rbp-8], 5

  j = i++; /*
  mov eax, DWORD PTR [rbp-4]  // move i([rbp-4]) value to register eax <-- 10
  lea edx, [rax+1]            // increment the register rax value(10) with +1 and move in edx <-- 11
  mov DWORD PTR [rbp-4], edx  // move edx register to i([rbp-4]) <-- 11 
  mov DWORD PTR [rbp-8], eax  // move eax(10) value to j([rbp-8]) <--10  */
  cout << "i: " << i << ", j: " << j << endl;
  // OUTPUT: i: 11, j: 10

  j = ++i; /*
  add DWORD PTR [rbp-4], 1    // add in i(rbp-4]) whch has value 10 with 1, i([rbp-4]) <-- 11
  mov eax, DWORD PTR [rbp-4]  // now move i([rbp-4]) value(11) to eax register (eax <-- 11)
  mov DWORD PTR [rbp-8], eax  // now move eax(11) value to j([rbp-8]) <-- 11 */
  cout << "i: " << i << ", j: " << j << endl;
  // OUTPUT: i: 12, j: 12

  return 0;
}
