
#include <iostream>
using namespace std;

//#define STATIC_OBJECT 1
#define STATIC_GLOBAL_OBJECT 2

#ifdef STATIC_OBJECT

/*
When are static objects destroyed?
  Remain Careful from these two persons
  new friends and old enemies — Kabir

  What is static keyword in C++?
  static keyword can be applied to local variables, functions, class’ data members and objects in C++. 
  static local variable retain their values between function call and initialized only once. 
  static function can be directly called using the scope resolution operator preceded by class name.
  C++ also supports static objects.

  What are static objects in C++?
  An object become static when static keyword is used in its declaration. See the following two statements for example in C++.

               Test t;             // Stack based object
               static Test t1;     // Static object 

  First statement when executes creates object on stack means storage is allocated on stack. 
  Stack based objects are also called automatic objects or local objects. 
  static object are initialized only once and live until the program terminates. 
  Local object is created each time its declaration is encountered in the execution of program.

  static objects are allocated storage in static storage area. static object is destroyed at the termination of program. 
  C++ supports both local static object and global static object

  Following is example that shows use of local static object.
*/

class Test {
public:
    Test() {
        std::cout << "Constructor is executed\n";
    }
    ~Test() {
        std::cout << "Destructor is executed\n";
    }
};
void myfunc() {
    static Test obj;
} // Object obj is still not destroyed because it is static
 
int main() {
    std::cout << "main() starts\n";
    myfunc();    // Destructor will not be called here
    std::cout << "main() terminates\n";
    return 0;
}

/* Output:

   main() starts
   Constructor is executed
   main() terminates
   Destructor is executed 

   If we observe the output of this program closely, we can see that the destructor for the local object named obj is not called 
   after it’s constructor is executed because the local object is static so it has scope till the lifetime of program so 
   it’s destructor will be called when main() terminates. 

   What happens when we remove static in above program?
   As an experiment if we remove the static keyword from the global function myfunc(), we get the output as below:

   main() starts
   Constructor is called
   Destructor is called
   main() terminates

   This is because the object is now stack based object and it is destroyed when it is goes out of scope and its destructor 
   will be called.

*/
#endif


#ifdef STATIC_GLOBAL_OBJECT
/*
  How about global static objects?
  The following program demonstrates use of global static object. */

class Test {
public:
    int a;
    Test() {
        a = 10;
        std::cout << "Constructor is executed\n";
    }
    ~Test() {
        std::cout << "Destructor is executed\n";
    }
};

static Test obj;

int main() {
    std::cout << "main() starts\n";
    std::cout << obj.a;
    std::cout << "\nmain() terminates\n";
    return 0;
}

/* Output:

Constructor is executed
main() starts
10
main() terminates
Destructor is executed */

#endif
