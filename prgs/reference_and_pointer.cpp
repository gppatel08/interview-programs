#include <iostream>
using namespace std;

/*

1. Memory Address - same address for reference but different for pinter
2. Reassignment is not possible with reference
3. NULL value cant be assigned for reference (int &a = NULL)
4. Arithmatic Operations are not provided for references ( a++ not allowd but (&a)++ yes)
5. Indirection - one level of indirection in reference as allowd but for pointer n level.

*/

int main() {
  int i = 0;
  int &r = i;  //reference
  int *p = &i; // pointer

  cout << "&i = " << &i << ", &r = " << &r << ", &p = " << &p << endl;

  int var = 90;
  r = var;

  cout << "i = " << i << ", r = " << r << ", var = " << var << endl;

  p = &var;
  *p = 60;
  cout << "i = " << i << ", var = " << var << ", *p = " << *p << endl;

  int a = 20;
  int &b = a;
  int &c = b;
  
  cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
  
  return 0;
}
