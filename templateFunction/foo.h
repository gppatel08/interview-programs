/*
  Why Template Functions Only Defined Inside Header Files?
*/

#ifndef foo_h
#define foo_h

#include <iostream>

template<typename T>
class Foo{
  T _val;
  public:
    T getValue();
    void setValue(T vale);

};

/*
if NONE of the case is enabled then below error we will get:
/tmp/ccTta1zJ.o: In function `main':
main.cpp:(.text+0x25): undefined reference to `Foo<int>::setValue(int)'
main.cpp:(.text+0x31): undefined reference to `Foo<int>::getValue()'
collect2: error: ld returned 1 exit status
*/

//#define Case_I 1   // g++ main.cpp  -o m
//#define Case_II 2  // g++ main.cpp  -o m
#define Case_III 3   // g++ main.cpp  foo.cpp -o m

#ifdef Case_I
#include "foo.cpp" // if we add this line then it will work
#endif

#ifdef Case_II 
template<typename T>
T Foo<T>::getValue() { return _val; }

template<typename T>
void Foo<T>::setValue(T value) { _val = value; }
#endif

#endif
