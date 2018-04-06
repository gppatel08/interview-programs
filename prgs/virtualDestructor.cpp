/*
Virtual Destructor:

    Deleting a derived class object using a pointer to a base class that has a non-virtual destructor results in 
    undefined behavior. To correct this situation, the base class should be defined with a virtual destructor. 
    For example, following program results in undefined behavior.

    Although the output of following program may be different on different compilers
*/

/* CPP program without virtual destructor causing undefined behavior */
#include<iostream> 
using namespace std;
 
//#define WITHOUT_VIRTUAL_KEYWORD 1
#define WITH_VIRTUAL_KEYWORD 2

#ifdef WITHOUT_VIRTUAL_KEYWORD
class base {
  public:
    base() { cout<<"Constructing base \n"; }
    ~base() { cout<<"Destructing base \n"; }     
};
 
class derived: public base {
  public:
    derived() { cout<<"Constructing derived \n"; }
    ~derived() { cout<<"Destructing derived \n"; }
};
 
int main(void)
{
  derived *d = new derived();  
  base *b = d;

  delete b;

  return 0;
}
/* OUTPUT:

Constructing base 
Constructing derived 
Destructing base

*/
#endif


#ifdef WITH_VIRTUAL_KEYWORD

/* Making base class destructor virtual guarantees that the object of derived class is destructed properly, 
   i.e., both base class and derived class destructors are called. For example, 
  
   As a guideline, any time you have a virtual function in a class, you should immediately add a virtual destructor 
   (even if it does nothing). This way, you ensure against any surprises later. */

class base {
  public:
    base() { cout<<"Constructing base \n"; }
    virtual ~base() { cout<<"Destructing base \n"; }     
};
 
class derived: public base {
  public:
    derived() { cout<<"Constructing derived \n"; }
    ~derived() { cout<<"Destructing derived \n"; }
};
 
int main(void)
{
  derived *d = new derived();  
  base *b = d;

  delete b;

  return 0;
}

/* OUTPUT:

Constructing base 
Constructing derived 
Destructing derived 
Destructing base

*/
#endif
