/*
A virtual function is a member function in base class that you expect to redefine in 
derived classes.
*/

#include <iostream>
using namespace std;

//#define CASE_I 1
//#define CASE_II 2
#define CASE_III 3

#ifdef CASE_I
/* 
 We created the Weapon class and derived two classes Bomb and Gun to load features of respective weapons.
*/

class Weapon
{
    public:
       void loadFeatures() { cout << "Loading weapon features.\n"; }
};

class Bomb : public Weapon
{
    public:
       void loadFeatures() { cout << "Loading bomb features.\n"; }
};

class Gun : public Weapon
{
    public:
       void loadFeatures() { cout << "Loading gun features.\n"; }
};

int main()
{
    Weapon *w = new Weapon;
    Bomb *b = new Bomb;
    Gun *g = new Gun;

    w->loadFeatures();
    b->loadFeatures();
    g->loadFeatures();

    return 0;
}
/* OUTPUT:
Loading weapon features.
Loading bomb features.
Loading gun features.
*/
#endif

#ifdef CASE_II
class Weapon
{
    public: 
       void features() { cout << "Loading weapon features.\n"; }
};

class Bomb : public Weapon
{
    public: 
       void features() { cout << "Loading bomb features.\n"; }
};

class Gun : public Weapon
{
    public: 
       void features() { cout << "Loading gun features.\n"; }
};

/*
 However, our game project started getting bigger and bigger. And, we decided to create a 
 separate Loader class to load weapon features.

 This Loader class loads additional features of a weapon depending on which weapon is selected.
 The loadFeatures() loads the feature of a specific weapon.
*/
class Loader
{
   public:
     void loadFeatures(Weapon *weapon)
     {
        weapon->features();
     }     
};

int main()
{
    Loader *l = new Loader;
    Weapon *w;
    Bomb b;
    Gun g;

    w = &b;
    l->loadFeatures(w);

    w = &g;
    l->loadFeatures(w);

    return 0;
}

/* OUTPUT:
Loading weapon features.
Loading weapon features.

 Our implementation seemed correct. However, weapon features was loaded 3 times. Why?

 Initially, the Weapon object w1 is pointing to the b1 object (of Bomb) class. And, we tried to load the features 
 of Bomb object by passing it to loadFeatures() function using l object to pointer (of Loader class).

 Similarly, we tried to load the features of Gun object.

 However, the loadFeatures() function of the Loader class takes pointer to object of a Weapon class as an argument:

         void loadFeatures(Weapon *weapon)

 That's the reason weapon features are loaded 3 times. To solve this issue, we need to make function of 
 base class (Weapon class) virtual using virtual keyword.

class Weapon
{
    public:
      virtual void features()
         { cout << "Loading weapon features.\n"; }
};

*/
#endif


#ifdef CASE_III
/*
 Using Virtual Function to Solve the Problem
 Also, notice that, the l->loadFeatures(w) function calls the function of different classes depending upon what l object is 
 pointing. Using virtual function made our code not only clearer but flexible too.*/

class Weapon
{
    public:
      virtual void features()
         { cout << "Loading weapon features.\n"; }
};

class Bomb : public Weapon
{
    public:
       void features()
         { cout << "Loading bomb features.\n"; }
};

class Gun : public Weapon
{
    public:
       void features()
         { cout << "Loading gun features.\n"; }
};


// If we want to add another weapon (let's say knife), we can easily add and load features of it. How?
//It's worth noticing that we didn't changed anything in the Loader class to load features of knife.
class Knife : public Weapon
{
    public:
       void features()
         { cout << "Loading knife features.\n"; }
};

class Loader
{
   public:
     void loadFeatures(Weapon *weapon)
     {
        weapon->features();
     }     
};

int main()
{
    Loader *l = new Loader;
    Weapon *w;
    Bomb b;
    Gun g;

    w = &b;
    l->loadFeatures(w);

    w = &g;
    l->loadFeatures(w);

    Knife k; 
    w = &k; 
    l->loadFeatures(w);

    return 0;
}

/* OUTPUT:
Loading bomb features.
Loading gun features.
Loading knife features.
*/
#endif
