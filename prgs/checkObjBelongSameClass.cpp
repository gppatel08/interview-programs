/*
How to check two different object belong to same class in C++?
Answer: by using typeid() from typeinfo header file.

*/

#include <iostream>
#include <typeinfo>

using namespace std;

class A{};

class B{};

int main() {
  A a1, a2;
  B b1, b2;

  if(typeid(a1) == typeid(b1)) 
    cout << "Equal : A->a1, B->b1" << endl;
  else
    cout << "Not Equal : A->a1, B->b1" << endl;

  if(typeid(a1) == typeid(a2)) 
    cout << "Equal : A->a1, A->a2" << endl;
  else
    cout << "Not Equal : A->a1, A->a2" << endl;

   if(&a1 == &a2)
    cout << "Equal : a1, a2" << endl;
   else
    cout << "Not Equal : a1, a2" << endl;

  return 0;
}

/*
Not Equal : A->a1, B->b1
Equal : A->a1, A->a2
Not Equal : a1, a2
*/
