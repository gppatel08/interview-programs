/*
Factory Design Pattern:
-----------------------
1. It creates object for you, rather you initiating object directly.
2. FDP is also known as "Virtual constructor". (C++ doesn't support viratual constructor)

How to Implement FDP:
---------------------
Define an interface or an abstract class for creating an object but let the subclass decide which class to initiate.

Factory Design Pattern is very basic design pattern and it is one of the creational design pattern. 
In this design pattern we create a factory method and  we pass type to this method and 
it returns that type's object.

*/


#include <iostream>
using namespace std;

class Toy {
  protected:
    string name;
    float price;
  public:
    virtual void prepareParts() = 0;
    virtual void combineParts() = 0; 
    virtual void assembleParts() = 0;
    virtual void applyLabel() = 0;
    virtual void showProduct() = 0;
};

class Car: public Toy {
  //Make all constructor private or protected!
  public:
   void prepareParts() { cout << "Preparing Car Parts.!" << endl; }
   void combineParts() { cout << "Combining Car Parts.!" << endl; }
   void assembleParts() { cout << "Assembling Car Parts.!" << endl; }
   void applyLabel() { cout << "Applying Car Label.!" << endl; name = "car"; price = 10;}

   void showProduct() { cout << "Name: " << name << ", Price: " << price << endl; }
};

class Bike: public Toy {
  //Make all constructor private or protected!
  public:
   void prepareParts() { cout << "Preparing Bike Parts.!" << endl; }
   void combineParts() { cout << "Combining Bike Parts.!" << endl; }
   void assembleParts() { cout << "Assembling Bike Parts.!" << endl; }
   void applyLabel() { cout << "Applying Bike Label.!" << endl; name = "Bike"; price = 50;}

   void showProduct() { cout << "Name: " << name << ", Price: " << price << endl; }
};

class Plane: public Toy {
  //Make all constructor private or protected!
  public:
   void prepareParts() { cout << "Preparing Plane Parts.!" << endl; }
   void combineParts() { cout << "Combining PLane Parts.!" << endl; }
   void assembleParts() { cout << "Assembling Plane Parts.!" << endl; }
   void applyLabel() { cout << "Applying Plane Label.!" << endl; name = "Plane"; price = 100;}

   void showProduct() { cout << "Name: " << name << ", Price: " << price << endl; }
};

class ToyFactory {
  public:
    static Toy* createToy(int type) {
      Toy *toy = NULL;

      switch(type) {
        case 1:
          toy = new Car;
          break;
        case 2:
          toy = new Bike;
          break;
        case 3:
          toy = new Plane;
          break;
        default:
          cout << "Invalid toy type please re-enter type. " << endl;
          return NULL;
      }

      toy->prepareParts();
      toy->combineParts();
      toy->assembleParts();
      toy->applyLabel();
 
      return toy;
    }
};


int main() {
  int type;
  while(1) {
    cout << "Enter type or zero for exit: " << endl;
    cin >> type;
    if(!type)
      break;

    Toy *v = ToyFactory::createToy(type);
    if(v) {
      v->showProduct();
      delete v;
    }
  }

  cout << "Exit.." << endl;
  return 0;
}
