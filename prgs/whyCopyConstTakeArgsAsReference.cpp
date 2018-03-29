#include <iostream>

using namespace std;

class Foo {
    int _bar;
  public:
    Foo() {}
    /* error: invalid constructor; you probably meant ‘Foo (const Foo&)’
     Foo(const Foo obj) { _bar = obj._bar; }
     Here if we wont give pass by refernce, then it will be infinite call*/
    Foo(const Foo &obj) { _bar = obj._bar; }
    void setBar(int newBar) { _bar = newBar; }
    int getBar() { return _bar; }
};

int main() {
  Foo f1;
  f1.setBar(10);

  Foo f2 = f1;  // here copy constructor will be called
  cout << "f2 : " << f1.getBar() << endl;
  return 0;
}
