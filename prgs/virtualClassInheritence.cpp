/* Virtual inheritance is a C++ technique that ensures only one copy of a base class's member variables are inherited by 
   grandchild derived classes.

                X
               ^ ^
              /   \
     virtual /     \ virtual
            A       B
             ^     ^
              \   /
               \ /
                C

  Without virtual inheritance, if classes A and B both inherit from class X, and class C inherits from classes A and B, 
  then class C will contain two copies of X's member variables: one via A, and one via B. 
  These will be accessible independently, using scope resolution.

  Instead, if classes A and B inherit virtually from class X, then objects of class C will contain only one set of the member 
  variables from class X. 

  This feature is most useful for multiple inheritance, as it makes the virtual base a common subobject for the deriving class 
  and all classes that are derived from it. This can be used to avoid the diamond problem by clarifying ambiguity over which 
  ancestor class to use, as from the perspective of the deriving class the virtual base (X) acts as though it were the 
  direct base class of C, not a class derived indirectly through its base (A).

  It is used when inheritance represents restriction of a set rather than composition of parts. 
  In C++, a base class intended to be common throughout the hierarchy is denoted as virtual with the virtual keyword.
*/

struct Animal {
  virtual ~Animal() { }
  virtual void eat();
};

struct Mammal : Animal {
  virtual void breathe();
};

struct WingedAnimal : Animal {
  virtual void flap();
};

// A bat is a winged mammal
struct Bat : Mammal, WingedAnimal {
};

Bat bat;


  /* As declared above, a call to bat.eat() is ambiguous because there are two Animal (indirect) base classes in Bat, 
     so any Bat object has two different Animal base class subobjects. So an attempt to directly bind a reference to the 
     Animal subobject of a Bat object would fail, since the binding is inherently ambiguous:

     Bat b;
     Animal &a = b; // error: which Animal subobject should a Bat cast into, 
                    // a Mammal::Animal or a WingedAnimal::Animal?

     To disambiguate, one would have to explicitly convert bat to either base class subobject:

     Bat b;
     Animal &mammal = static_cast<Mammal&> (b); 
     Animal &winged = static_cast<WingedAnimal&> (b);

    In order to call eat(), the same disambiguation, or explicit qualification is needed: 
               static_cast<Mammal&>(bat).eat() or 
               static_cast<WingedAnimal&>(bat).eat() or alternatively 
               bat.Mammal::eat() and 
               bat.WingedAnimal::eat(). 

    Explicit qualification not only uses an easier, uniform syntax for both pointers and objects but also allows for 
    static dispatch, so it would arguably be the preferable method. 

    This situation is sometimes referred to as diamond inheritance because the inheritance diagram is in the shape of a diamond. 
    Virtual inheritance can help to solve this problem.

*/

struct Animal {
  virtual ~Animal() { }
  virtual void eat();
};

// Two classes virtually inheriting Animal:
struct Mammal : virtual Animal {
  virtual void breathe();
};

struct WingedAnimal : virtual Animal {
  virtual void flap();
};

// A bat is still a winged mammal
struct Bat : Mammal, WingedAnimal {
};


/*  Suppose you have two derived classes B and C that have a common base class A, and you also have another class D that 
    inherits from B and C. You can declare the base class A as virtual to ensure that B and C share the same subobject of A.

    In the following example, an object of class D has two distinct subobjects of class L, one through class B1 and another 
    through class B2. You can use the keyword virtual in front of the base class specifiers in the base lists of 
    classes B1 and B2 to indicate that only one subobject of type L, shared by class B1 and class B2, exists.

For example:

class L {  }; // indirect base class
class B1 : virtual public L {  };
class B2 : virtual public L {  };
class D : public B1, public B2 {  }; // valid


Using the keyword virtual in this example ensures that an object of class D inherits only one subobject of class L.
A derived class can have both virtual and nonvirtual base classes. For example:

class V {  };
class B1 : virtual public V {  };
class B2 : virtual public V {  };
class B3 : public V {  };
class X : public B1, public B2, public B3 { };

In the above example, class X has two subobjects of class V, one that is shared by classes B1 and B2 and one through class B3.

*/

