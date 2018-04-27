#include <iostream>
using namespace std;

class A {
    int a;
    const int b;
    static int c;
    char *d;
  public: 
    A(int _a=5, int _b=10, char _d='a'): a(_a), b(_b) { 
      cout << "Constructor" << endl; 
      d = new char;
      *d = _d;
    }
    void show() {
      cout << "a: " << a <<endl;
      cout << "b: " << b <<endl;
      cout << "c: " << A::c <<endl;
      cout << "d: " << *d <<endl;
    }
    ~A() { 
      cout << "Destructor" << endl; 
      delete d;
    }
};

int A::c = 20;

int main() {
  A a1(50, 100, 'G');
  a1.show();

  //A *a2 =  new A;
  //delete a2;
  
  return 0;
}
