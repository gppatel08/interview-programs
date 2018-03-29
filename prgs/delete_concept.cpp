/*
How delete[] know how many objects to delete?
Ans: 1. Over allocation (extra WORDSIZE 4 or 8 bytes) 
     2. Associative array
*/

#include <iostream>
int const n = 10;

#define Over_Allocation 1
//#define Associative_Array 2

class Base {
  public:
    int b_var;
};

int main() {

#ifdef Over_Allocation
  /* tmp - 0 1 2 3 4 5 6 .. 43
     p   -         4 5 6 7 8 .. 43 
     n   - 0 1 2 3
  */

  Base *bp = new Base[n];
  /*
  char* tmp = (char*)operator new[](WORDSIZE + n *sizeof(Base));
  Base *p = (Base*) (tmp + WORDSIZE);
  *(size_t*)tmp = n;
  for(int i = 0; i < n; i++)
    new(p + i)Base();  //placement new
  */

  delete[] bp;
  /*
  size_t n = *(size_t*)((char*)p - WORDSIZE);
  while(n-- !=0)
    (p + n)->~Base(); // call destrcutor explicitly if call placement new
  operator delete[] ((char*)p - WORDSIZE);
  */
#endif

#ifdef Associative_Array
  Base *bp1 = new Base[n];
  /*
  Base* bp1 = (Base*)operator new[](n *sizeof(Base));
  size_t i;
  for(i = 0; i < n; i++)
    new(bp + i)Base();  //placement new
  associativeArray.insert(bp1, n);
  */

  delete[] bp1;
  /*
  size_t n = associativeArray.lookup(bp1);
  while(n-- !=0)
    (bp1 + n)->~Base();
  operator delete[] (bp1);
  */
#endif
  return 0;
}
