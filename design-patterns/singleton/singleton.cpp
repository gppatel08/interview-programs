/* 
Singleton Designe Pattern
=========================
a. The Singleton pattern ensures that a class has only one instance and provides a global point of access to that instance. 
b. It is named after the singleton set, which is defined to be a set containing one element. 
c. This is useful when exactly one object is needed to coordinate actions across the system.

Check list -:
-------------
 1. Define a private static attribute in the "single instance" class.
 2. Define a public static accessor function in the class.
 3. Do "lazy initialization" (creation on first use) in the accessor function.
 4. Define all constructors to be protected or private.
 5. Clients may only use the accessor function to manipulate the Singleton.

Like a global variable, the Singleton exists outside of the scope of any functions. 
Traditional implementation uses a static member function of the Singleton class, which will create a single instance of 
the Singleton class on the first call, and forever return that instance. 

*/

#include <iostream>
#include <memory>

using namespace std;

class StringSingleton {
 public:
     // Some accessor functions for the class, itself
     std::string GetString() const { return mString; }
     void SetString(const std::string &newStr) { mString = newStr; }
 
     // The magic function, which allows access to the class from anywhere
     // To get the value of the instance of the class, call: StringSingleton::Instance().GetString();
     static StringSingleton &Instance()
     {
         // This line only runs once, thus creating the only instance in existence
         static std::auto_ptr<StringSingleton> instance( new StringSingleton );

         // dereferencing the variable here, saves the caller from having to use the arrow operator, 
         // and removes temptation to try and delete the returned instance.
         return *instance; // always returns the same instance
     }

 
 private: 
     // We need to make some given functions private to finish the definition of the singleton
     StringSingleton(){} // default constructor available only to members or friends of this class
 
     // Note that the next two functions are not given bodies, thus any attempt to call them implicitly will return 
     // as compiler errors. This prevents accidental copying of the only instance of the class.
     StringSingleton(const StringSingleton &old); // disallow copy constructor
     const StringSingleton &operator=(const StringSingleton &old); //disallow assignment operator
 
     // Note that although this should be allowed, some compilers may not implement private destructors
     // This prevents others from deleting our one single instance, which was otherwise created on the heap
     //~StringSingleton(){} 

 private: 
     // private data for an instance of this class
     std::string mString;
 };

/*
Applications of Singleton Class:
================================
One common use of the singleton design pattern is for application configurations. 
Configurations may need to be accessible globally, and future expansions to the application configurations may be needed. 
The subset C's closest alternative would be to create a single global struct. 
This had the lack of clarity as to where this object was instantiated, as well as not guaranteeing the existence of the 
object.
*/

int main() {
    cout << "singlton str : " << StringSingleton::Instance().GetString() << endl; 

    StringSingleton::Instance().SetString("Hello");
   
    cout << "singlton str : " << StringSingleton::Instance().GetString() << endl; 
    cout << "singlton str : " << StringSingleton::Instance().GetString() << endl; 
    
    StringSingleton::Instance().SetString("World");

    cout << "singlton str : " << StringSingleton::Instance().GetString() << endl; 
    cout << "singlton str : " << StringSingleton::Instance().GetString() << endl; 

    return 0;
}


