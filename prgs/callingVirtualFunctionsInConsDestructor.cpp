/*
NOTE: It is highly recommended to avoid calling virtual methods from constructor/destructor.

  Calling virtual functions from a constructor or destructor is considered dangerous most of the times and 
  must be avoided whenever possible. All the C++ implementations need to call the version of the function defined at the level 
  of the hierarchy in the current constructor and not further.

  You can call a virtual function in a constructor. The Objects are constructed from the base up, “base before derived”.

  CPP program to illustrate calling virtual methods in constructor/destructor */

#include<iostream>
using namespace std;
 
class dog {
public:
    dog() {
        cout<< "Constructor called" <<endl;
        bark() ;
    }
 
    ~dog() { bark(); }
 
    virtual void bark() { cout<< "Virtual method called" <<endl; }
 
    void seeCat() { bark(); }
};
 
class Yellowdog : public dog {
public:
        Yellowdog() { cout<< "Derived class Constructor called" <<endl; }
        void bark() { cout<< "Derived class Virtual method called" <<endl; }
};
 
int main() {
    Yellowdog d;
    d.seeCat();
}

/* Output:

Constructor called
Virtual method called
Derived class Constructor called
Derived class Virtual method called
Virtual method called 

Explanation:

  1. bark method in dog class is invoked in constructor as well as destructor.
  2. When the object of Yellowdog is created, constructor of dog and then of Yellowdog is called and 
     reverse order of calling for destructor.
  3. Although, bark method is virtual method but when it is called inside constructor it will behave as non-virtual method 
     because by the time constructor of dog(base) class is called as in above code, Yellowdog(derived) class is not constructed 
     by that time.
  4. Therefore, it is dangerous to call the member function of class whose object is not constructed yet and compiler calls the 
     dog class verison of bark method. And same is with the destructor, when object ‘d’ of Yellowdog gets destroyed, destructor 
     of Yellowdog class is called first and then destructor for dog class is called but by this time Yellowdog is already 
     destroyed, hence dog class verison of bark is called.
*/
