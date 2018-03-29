#include "foo.h"

template<typename T>
T Foo<T>::getValue() { return _val; }

template<typename T>
void Foo<T>::setValue(T value) { _val = value; }


#ifdef Case_III
template class Foo<int>;
template class Foo<float>;
#endif
