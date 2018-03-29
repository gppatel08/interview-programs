/* what is placement new in C++ */

#include <iostream>
using namespace std;

class Base {
    int a;
  public:
    Base() { cout << "constructor" <<  endl; }
    ~Base() { cout << "destructor" <<  endl; }
};

int main() {
  /* Normal Case*/
  /* switching from user mode to kernel mode is not feasible if we have 1000 objects 
  construction at once, hence we go for placement new case */
  cout << "Normal Case:" << endl;
  Base *obj = new Base();
  delete obj;

  /* Placement new case */
  /* asking kernel once for the how much memory u need at once i
     its easy to search the 40 bytes at only once insteasd of each object evry time.*/
  cout << "placement new case:" << endl;
  char *memory =  new char[10 * sizeof(Base)];

  /*instead of asking for memory from kernel we use the memory whihc is already given
    by kernel above through char *memory =  new char[10 * sizeof(Base)]; */
  Base *obj1 = new (&memory[0])Base();
  Base *obj2 = new (&memory[4])Base();
  Base *obj3 = new (&memory[8])Base();

  obj1->~Base();
  obj2->~Base();
  obj3->~Base();

  delete[] memory;
  return 0;
}
