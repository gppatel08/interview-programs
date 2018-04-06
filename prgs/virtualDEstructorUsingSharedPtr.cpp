/*
Virtual destruction using shared_ptr in C++:
============================================

  As we know that, deleting a derived class object using a pointer to a base class that has a non-virtual destructor results 
  in undefined behavior. Thus, we make the base class destructor virtual so that the polymorphic objects are being deleted 
  properly in the correct order (i.e. the reverse order of their creation).

  Similar behavior can also be achieved by using a shared_ptr without having the Base class destructor virtual. 

  How shared_ptr achieves this magical behavior?
    The shared_ptr remembers the pointer type used during construction. For example,

        If you say shared_ptr{ new Derived {} }, then shared_ptr will internally store a Derived*. 
        If you say shared_ptr{ new Base {} }, then it stores a Base*. 
    
    When the shared_ptr is destructed, it calls delete on the stored pointer. 
    Naturally, with non-virtual destructors, for Base* it will call Base::~Base and for Derived* it will call Derived::~Derived.

  Important points :
  ------------------
     1. This behavior is achieved by shared_ptr only.
     2. This behavior is not achieved by using unique_ptr.
     3. All the classes in STL do not have virtual destructor, so be careful if you inherit from them. 
        If you want to inherit, you can use shared_ptr in that case to have the smart destruction applied.

  Let us have a look on the following code: */

//#define VIRTUAL_DESTRUCTION_USING_SHARED_PTR 1
#define VIRTUAL_DESTRUCTION_USING_SHARED_PTR_EXCEPTION 2

#ifdef VIRTUAL_DESTRUCTION_USING_SHARED_PTR

// Program to show order of destruction of objects using shared_ptr
#include <iostream>
#include <memory>
using namespace std;
 
class Base {
public:
    Base() { cout << "Constructing Base" << endl; }
    ~Base() { cout << "Destructing Base" << endl; }
};
 
class Derived : public Base {
public:
    Derived() { cout << "Constructing Derived" << endl; }
    ~Derived() { cout << "Destructing Derived" << endl; }
};
 
int main() {
    std::shared_ptr<Base> sp{ new Derived };
 
    // make_shared can also be used to create sp.
    // std::shared_ptr<Base> sp{std::make_shared<Derived>()};
    // Use sp
}

/*
Output:

  Constructing Base
  Constructing Derived
  Destructing Derived
  Destructing Base

  As shown in the above output, there is no need to make the destructor of the Base class virtual anymore, 
  while achieving the virtual destructor behavior at the same time.*/

#endif


#ifdef VIRTUAL_DESTRUCTION_USING_SHARED_PTR_EXCEPTION

/*
Exceptional Condition : Initializing from Base
==============================================
Consider the following example:
    Program to show exception to this behavior while using shared_ptr */

#include <iostream>
#include <memory>
using namespace std;
 
class Base {
public:
    Base() { cout << "Constructing Base" << endl; }
    ~Base() { cout << "Destructing Base" << endl; }
};
 
class Derived : public Base {
public:
    Derived() { cout << "Constructing Derived" << endl; }
    ~Derived() { cout << "Destructing Derived" << endl; }
};
 
int main(){
    Base* p = new Derived{};
    std::shared_ptr<Base> sp{ p };
}

/* Output:

Constructing Base
Constructing Derived
Destructing Base */

#endif
