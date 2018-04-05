/* 
One of the important concepts of OOP is data hiding, i.e., a nonmember function cannot access an object's private or protected data.

But, sometimes this restriction may force programmer to write long and complex codes. So, there is mechanism built in C++ programming to access private or protected data from non-member functions.

This is done using a friend function or/and a friend class. 

//1. friend Function in C++
If a function is defined as a friend function then, the private and protected data of a class can be accessed using the function.

   The complier knows a given function is a friend function by the use of the keyword friend.

   For accessing the data, the declaration of a friend function should be made inside the body of the class 
   (can be anywhere inside class either in private or public section) starting with keyword friend.

Declaration of friend function in C++:
-------------------------------------
class class_name
{
    ... .. ...
    friend return_type function_name(argument/s);
    ... .. ...
}


  Now, you can define the friend function as a normal function to access the data of the class. 
  No friend keyword is used in the definition.

class className
{
    ... .. ...
    friend return_type functionName(argument/s);
    ... .. ...
}

return_type functionName(argument/s)
{
    ... .. ...
    // Private and protected data of className can be accessed from
    // this function because it is a friend function of className.
    ... .. ...
}

*/

#ifdef CASE_I
/* C++ program to demonstrate the working of friend function.*/
#include <iostream>
using namespace std;

class Distance
{
    private:
        int meter;
    public:
        Distance(): meter(0) { }
        //friend function
        friend int addFive(Distance);
};

// friend function definition
int addFive(Distance d)
{
    //accessing private data from non-member function
    d.meter += 5;
    return d.meter;
}

int main()
{
    Distance D;
    cout<<"Distance: "<< addFive(D);
    return 0;
}

#endif

/*
 Here, friend function addFive() is declared inside Distance class. So, the private data meter can be accessed from this function.

 A more meaningful use would to when you need to operate on objects of two different classes. 
 That's when the friend function can be very helpful.

 We can definitely operate on two objects of different classes without using the friend function 
 but the program will be long, complex and hard to understand.
*/

#ifdef CASE_II
/* Example 2: Addition of members of two different classes using friend Function
   In this program, classes A and B have declared add() as a friend function. 
   Thus, this function can access private data of both class.

   Here, add() function adds the private data numA and numB of two objects objectA and objectB, 
   and returns it to the main function.

   To make this program work properly, a forward declaration of a class class B should be made as shown in the above example.

   This is because class B is referenced within the class A using code: friend int add(A , B);.
*/

#include <iostream>
using namespace std;

// forward declaration
class B;
class A {
    private:
      int numA;
    public:
      A(): numA(12) { }
      // friend function declaration
      friend int add(A, B);
};

class B {
    private:
       int numB;
    public:
       B(): numB(1) { }
       // friend function declaration
       friend int add(A , B);
};

// Function add() is the friend function of classes A and B
// that accesses the member variables numA and numB
int add(A objectA, B objectB)
{
   return (objectA.numA + objectB.numB);
}

int main()
{
    A objectA;
    B objectB;
    cout<<"Sum: "<< add(objectA, objectB);
    return 0;
}
#endif

#ifdef CASE_III
/*
Friend Class in C++ Programming:
--------------------------------
Similarly, like a friend function, a class can also be made a friend of another class using keyword friend. For example:

... .. ...
class B;
class A
{
   // class B is a friend class of class A
   friend class B;
   ... .. ...
}

class B
{
   ... .. ...
}

When a class is made a friend class, all the member functions of that class becomes friend functions.

 In this program, all member functions of class B will be friend functions of class A. Thus, any member function of class B can 
 access the private and protected data of class A. But, member functions of class A cannot access the data of class B. */
#endif




#ifdef PUBLIC_PRIVATE_PROTECTED_CLASS_INHERITENCE

/*
Public, Protected and Private Inheritance in C++ Programming:-
--------------------------------------------------------------
   You can declare a derived class from a base class with different access control, 
   i.e., public inheritance, protected inheritance or private inheritance.

#include <iostream>
using namespace std;

class base
{
.... ... ....
};

class derived : access_specifier base
{
.... ... ....
};

     Note: Either public, protected or private keyword is used in place of access_specifier term used in the above code.

Example of public, protected and private inheritance in C++:
------------------------------------------------------------

class base 
{
	public:
		int x;
	protected:
		int y;
	private:
		int z;
};

class publicDerived: public base
{
	// x is public
	// y is protected
	// z is not accessible from publicDerived
};

class protectedDerived: protected base
{
	// x is protected
	// y is protected
	// z is not accessible from protectedDerived
};

class privateDerived: private base
{
	// x is private
	// y is private
	// z is not accessible from privateDerived
}


     ----------------------------------------------------------------------------------------------------------
     |                          Accessibility in PUBLIC Inheritance                                           |
     ----------------------------------------------------------------------------------------------------------
     |	Accessibility 				| private_variables | protected_variables | public_variables  |
     |---------------------------------------------------------------------------------------------------------
     |	Accessible from own class? 		|	YES	    |		YES	  |		YES   |
     |	Accessible from derived class? 		|	NO	    |		YES	  |		YES   |  
     |	Accessible from 2nd derived class? 	|	NO	    |		YES	  |		YES   |
     ----------------------------------------------------------------------------------------------------------

     -----------------------------------------------------------------------------------------------------------------------------------
     |                                       Accessibility in PROTECTED Inheritance                                                    |
     ----------------------------------------------------------------------------------------------------------------------------------|
     |  Accessibility                           | private_variables | protected_variables | public_variables                           |
     |---------------------------------------------------------------------------------------------------------------------------------|
     |  Accessible from own class?              |       YES         |           YES       |    YES                                     |
     |  Accessible from derived class?          |       NO          |           YES       |    YES(inherited as protected variables)   |  
     |  Accessible from 2nd derived class?      |       NO          |           YES       |    YES                                     |
     -----------------------------------------------------------------------------------------------------------------------------------

     -----------------------------------------------------------------------------------------------------------------------------------------
     |                                                  Accessibility in PRIVATE Inheritance                                                  |
     ------------------------------------------------------------------------------------------------------------------------------------------
     |  Accessibility                      | private_variables | protected_variables                   | public_variables                     |
     |-----------------------------------------------------------------------------------------------------------------------------------------
     |  Accessible from own class?         |       YES         |   YES                                 |  YES                                 |
     |  Accessible from derived class?     |       NO          |   YES(inherited as private variables) |  YES(inherited as private variables) |      |  Accessible from 2nd derived class? |       NO          |   NO                                  |  NO                                  |
     ------------------------------------------------------------------------------------------------------------------------------------------

*/



