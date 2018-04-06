/*
Question: What is the use of private destructor?
Answer  : Whenever we want to control destruction of objects of a class, we make the destructor private. 
          For dynamically created objects, it may happen that you pass a pointer to the object to a function and the function 
          deletes the object. If the object is referred after the function call, the reference will become dangling. 
          See this for more details.
          The simple answer to why I made the destructor private was that I didn't want anyone to be able to destroy the object.
*/

#include <iostream>
using namespace std;
 
//#define CASE_I 1	
//#define CASE_II 2	
//#define CASE_III 3	
//#define CASE_IV 4	
//#define CASE_V 5	
#define CASE_VI 6	


class Test {
  private:
    ~Test() {}
};

#ifdef CASE_I
/* The above program compiles and runs fine. It is not compiler error to create private destructors. */
int main(){ 

}
#endif


#ifdef CASE_II
/* The below program fails in compilation. The compiler notices that the local variable ‘t’ cannot be destructed 
   because the destructor is private. */
int main() { 
  Test t; 
}
/* OUTPUT:
privateDestructor.cpp: In function ‘int main()’:
privateDestructor.cpp:22:5: error: ‘Test::~Test()’ is private
     ~Test() {}
     ^
privateDestructor.cpp:37:8: error: within this context
   Test t; 
        ^
*/
#endif


#ifdef CASE_III
/* The below program works fine. There is no object being constructed, the program just creates a pointer of type “Test *”, 
   so nothing is destructed. */
int main() {
  Test *t; 
}
#endif


#ifdef CASE_IV
/* The below program also works fine. When something is created using dynamic memory allocation, 
   it is programmer’s responsibility to delete it. So compiler doesn’t bother. */
int main() {
  Test *t = new Test;
}
#endif

#ifdef CASE_V
/* The below program fails in compilation. When we call delete, desturctor is called. */
int main() { 
   Test *t = new Test;
   delete t;
}
/* OUTPUT:
privateDestructor.cpp: In function ‘int main()’:
privateDestructor.cpp:22:5: error: ‘Test::~Test()’ is private
     ~Test() {}
     ^
privateDestructor.cpp:72:11: error: within this context
    delete t;
           ^
*/
#endif


#ifdef CASE_VI
/* We noticed in the above programs, when a class has private destructur, only dynamic objects of that class can be created. 
   Following is a way to create classes with private destructors and have a function as friend of the class. 
   The function can only delete the objects. */

 
/* A class with private destuctor */
class Test1 {
private:
    ~Test1() {}
    friend void destructTest(Test1*);
};
 
// Only this function can destruct objects of Test
void destructTest(Test1* ptr)
{
    delete ptr;
}
 
int main()
{
    // create an object
    Test1 *ptr = new Test1;
 
    // destruct the object
    destructTest (ptr);
 
    return 0;
}
#endif
