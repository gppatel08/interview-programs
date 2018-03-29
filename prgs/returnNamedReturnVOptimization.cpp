/*
Return Value Optimization (RVO) and Named Return Value Optimization (NRVO)

Question: what is RVO nad NRVO in C++?
Answer  : it stands for Return Value Optimization (RVO) and Named Return Value Optimization (NRVO)  

*/

#include <iostream>
#include <vector>
using namespace std;

class Base {
  public:
    Base() { cout << "Base Constructor" << endl; }
    Base(const Base&) { cout << "Base Copy-Constructor" << endl; }
};

/* Here 1. Base constrctor will get called to create Base object
        2. since its returning Base object so it will be copied into temporary Base object localy and
           return, thats why here Base copy constructor will be called. */
Base func() { return Base(); } 


int main() {
  Base b = func(); // 3. Here again Base copy constructor will be called to copy into b.
  return 0;
}

/*
$ g++ -fno-elide-constructors returnNamedReturnVOptimization.cpp -o m
$ ./m
Base Constructor
Base Copy-Constructor
Base Copy-Constructor

//if we disable flag(-fno-elide-constructors), then it will avoid un-necessory creation of the objects 
$ g++ returnNamedReturnVOptimization.cpp -o m
$ ./m
Base Constructor

*/
