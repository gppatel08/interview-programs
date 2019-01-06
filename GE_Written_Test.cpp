/* Question 1: dynamic_cast up/down casting */

#include<iostream>
using namespace std;
// Base class must have vurtual function whether its public or private
class Base { virtual void fun(){} }; // error: if NO virtual function defined
class Derived : public Base {
    public:
        int a;
        //void fun(){}
};
int main() {
    try {
        Base *pba = new Derived;
        // Virtual function must NOT be private in Base, if you want call Derived obj's function through Base pointer
        //pba->fun();
        Base *pbb = new Base;
        Derived *pd;
        /* error: cannot dynamic_cast 'pba' (of type 'class Base*') to type 'class Derived*'
           (source type is not polymorphic) */
        pd = dynamic_cast<Derived*>(pba);
        if(pd == nullptr)
            cout << "First dynamic cast is null.!" << endl;
        /* error: cannot dynamic_cast 'pba' (of type 'class Base*') to type 'class Derived*'
           (source type is not polymorphic)*/
        pd = dynamic_cast<Derived*>(pbb);
        if(pd == nullptr)
            cout << "Second dynamic cast is null.!" << endl;
    }catch(exception &e) { cout << "Exception: " << e.what() << endl; }
    cout << "Exit Mian.!" << endl;
}
/*
OUTPUT:
Second dynamic cast is null.!
Exit Mian.!
*/

/* Question 2: Reference return from function */
#include<iostream>
using namespace std;
int& func() {
    int x = 10;
    int &y = x;
    return y;
}

int main() {
    int z = 15;
    z = func();
    cout << "z : " << z << endl;
}
/*
OUTPUT:
z : 10
*/


/* Question 3: Virtual function compile-time binding && run-time binding */
#include<iostream>
using namespace std;
class Base {
    // private: // Doubt why not compiling & calling fun()
    public: // Ok
        virtual void fun() { cout << "Base class fun() called." << endl; }
};
class Derived : public Base {
    private:
        void fun() { cout << "Derived class fun() called." << endl; }
};
int main() {
    Base *pb = new Derived;
    pb->fun();
}
/* access accessifier : public, private, protect check is at compile-time & virtual function call check is run-time.
OUTPUT:
	CASE I: (Base -> public -> virtual function) -> since function is public, so compile-time binding to function is OK.
	        run-time it check the vtable of real object type instance, and refer the vtable address of that function to call. 
		so even real object's function is private but still it will get the actual address from vtable to call the function.
	Derived class fun() called.

	CASE II: if we make Base -> Private and Derived -> public for above scenario, compiler error throw.
		 because at compile-time function is NOT accessible since Base -> private -> virtual function
*/


/* Question 4: public, private concept for member function call based on the type of pointer which do compile-time binding */
#include<iostream>
using namespace std;

//#define CASE_I 1
#define CASE_II 1
#ifdef CASE_I
class Base {
    public:
        int fun(int i){ cout << "int fun(int) : " << i << endl; }
};
class Derived: public Base {
    public:
        double fun(double d){ cout << "double fun(double) : " << d << endl; }
};

int main(){
    Derived *d = new Derived;
    d->fun(2); //implicit conversion from int to double, Hence double fun(double d) called
    d->fun(2.5);
}
/*
double fun(double) : 2
double fun(double) : 2.5
*/
#endif

#ifdef CASE_II
class Base {
    public:
        int fun(int i){ cout << "int fun(int) : " << i << endl; }
};
class Derived: public Base {
    private:
        double fun(double d){ cout << "double fun(double) : " << d << endl; }
};

int main(){
    //Derived *d = new Derived; //CASE A
    Base *d = new Derived;    //CASE B
    d->fun(2);
    d->fun(4.5);
}
/*
OUTPUT:
CASE A: 
    Since instance of object is Derived type and Derived::fun is private, so can't access private fun of Derived.
    error: 'double Derived::fun(double)' is private within this context
        d->fun(2);
    error: 'double Derived::fun(double)' is private within this context
        d->fun(4.5);

CASE B: implicit casting from double to int to this call -> d->fun(4.5) -> Base::int fun(int)
    int fun(int) : 2
    int fun(int) : 4
*/
#endif


/* Question 5: virtual destructor and virtual function call from constructor & destructor */

#include<iostream>
using namespace std;

class Base {
    public:
        Base(const string &ss):s(ss) { cout << "Base constructor.!" << endl; fun(ss); }
        virtual void fun(const string &){ cout << "Base::fun() " << endl; }
        virtual ~Base() { cout << "Base destructor.!" << endl; fun(s); }
    private:
        string s;
};
class Derived: public Base {
    public:
        Derived(const string &ss):Base(ss) { cout << "Derived constructor.!" << endl; }
        void fun(const string &ss){ cout << "Derived::fun() " << endl; s = ss; }
        ~Derived(){ cout << "Derived destructor.!" << endl;fun(s); }
    private:
        string s;
};

int main() {
    Base *b = new Derived("hello");
    cout << "--------------------------" << endl;
    delete b;
}
/*OUTPUT:
CASE I: When Base class destructor is virtual:
	Base constructor.!
	Base::fun()
	Derived constructor.!
	--------------------------
	Derived destructor.!
	Derived::fun()
	Base destructor.!
	Base::fun()

CASE I: When Base class destructor is NOT virtual:
	Base constructor.!
	Base::fun()
	Derived constructor.!
	--------------------------
	Base destructor.!
	Base::fun()
*/
