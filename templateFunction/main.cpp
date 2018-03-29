/* Why Template Functions Only Defined Inside Header Files?  -> foo.h */

#include "foo.h"

using namespace std;

int main() {
  Foo<int> obj;
  obj.setValue(10);
  cout << "value : " << obj.getValue() << endl;
  return 0;
}
