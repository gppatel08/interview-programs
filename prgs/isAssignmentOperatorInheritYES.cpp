/*
Is assignment operator inherited?
=================================
In C++, like other functions, assignement operator function is inherited in derived class.

For example, in the following program, base class assignment operator function can be accessed using the derived class object.*/

#include<iostream>
 
using namespace std;
 
class A {
 public:
   A & operator= (A &a) { 
    cout<<" base class assignment operator called " << endl;  
    return *this;
   }
};
 
class B: public A { };
 
int main()
{
  B a, b;
  a.A::operator=(b); //calling base class assignment operator function using derived class
  
  return 0;
}

/*
Output: base class assignment operator called
*/
