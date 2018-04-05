#include<iostream>
using namespace std;

void print(int times) {
  if(times == 0)
    return;

  cout << "C++: " << times << endl;
  --times;

  print(times);
  cout << "Reverse: " << times << endl;
}

int main() {
  print(5);
  return 0;
}
