/*
  When does compiler create default and copy constructors in C++?

  In C++, compiler creates a default constructor if we don’t define our own constructor. 
  Compiler created default constructor has empty body, i.e., it doesn’t assign default values to data members.

  Compiler also creates a copy constructor if we don’t write our own copy constructor. 
  Unlike default constructor, body of compiler created copy constructor is not empty, it copies all data members of passed 
  object to the object which is being created. 

  When should we write our own copy constructor?
  Don’t write a copy constructor if shallow copies are ok: In C++, If an object has no pointers or any run time allocation 
  of resource like file handle, a network connection..etc, a shallow copy is probably sufficient. 
  Therefore the default copy constructor, default assignment operator, and default destructor are ok and you don’t need to 
  write your own.*/


#include <iostream>
using namespace std;

//#define ONLY_COPY_CONSTRUCTOR 1
#define ONLY_DEFAULT_CONSTRUCTOR 2

#ifdef ONLY_COPY_CONSTRUCTOR 
/*
  What happens when we write only a copy constructor – does compiler create default constructor?
  Compiler doesn’t create a default constructor if we write any constructor even if it is copy constructor. 
  For example, the following program doesn’t compile.
*/
 
class Point
{
    int x, y;
public:
   Point(const Point &p) { x = p.x; y = p.y; }
};
 
int main()
{
    Point p1;  // COMPILER ERROR
    Point p2 = p1;
    return 0;
}
/*Output:
    COMPILER ERROR: no matching function for call to 'Point::Point()

defaultAndCopyConstructor.cpp: In function ‘int main()’:
defaultAndCopyConstructor.cpp:34:11: error: no matching function for call to ‘Point::Point()’
     Point p1;  // COMPILER ERROR
           ^
defaultAndCopyConstructor.cpp:29:4: note: candidate: Point::Point(const Point&)
    Point(const Point &p) { x = p.x; y = p.y; }
    ^
defaultAndCopyConstructor.cpp:29:4: note:   candidate expects 1 argument, 0 provided */
#endif

#ifdef ONLY_DEFAULT_CONSTRUCTOR
/* 
  What about reverse – what happens when we write a normal constructor and don’t write a copy constructor?
  Reverse is not true. Compiler creates a copy constructor if we don’t write our own. 
  Compiler creates it even if we have written other constructors in class. For example, the below program works fine.

  So we need to write copy constructor only when we have pointers or run time allocation of resource like file handle, 
  a network connection, etc */

class Point
{
    int x, y;
public:
   Point(int i, int j) { x = 10; y = 20; }
   int getX() { return x; }
   int getY() { return y; }
};
 
int main()
{
    Point p1(10, 20);
    Point p2 = p1; // This compiles fine
    cout << "x = " << p2.getX() << " y = " << p2.getY() << endl;
    return 0;
}

/* Output:
x = 10 y = 20 */

#endif
