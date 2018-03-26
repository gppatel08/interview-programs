/*
Abstract Factory Design Pattern:
--------------------------------
Abstract Factory Design Pattern is very basic design pattern and comes under creational design pattern, 
we generally call this as factory of factories which means there will be a factory which will create another factory, 
and finally the created factory will create family of related objects.

AFDP defines an abstract class for creating families of related objects but 
without specifying their concrete sub-class.

Why/When to use AFDP:
---------------------
1.  You need system to be independent of how objects are created, composed and represented.
2. show interface not implementation
3. system need to be configured with one of the multiple family of objects.
*/

#include <iostream>
using namespace std;

class Tire {
  protected:
    string name;
    int presure;
  public:
    Tire(string n, int presure):name(n), presure(presure) {}
    string getName() { return name; }
    int getPresure() { return presure; }
};

class SimpleTire: public Tire {
  public:
    SimpleTire():Tire("SimpleTire", 75) {}
};

class LuxuryTire: public Tire {
  public:
    LuxuryTire():Tire("LuxuryTire", 100) {}
};


class Body {
  protected:
    string name;
    int strength;
  public:
    Body(string n, int strength):name(n), strength(strength) {}
    string getName() { return name; }
    int getStrength() { return strength; }
};

class SimpleBody: public Body {
  public:
    SimpleBody():Body("SimpleBody", 75) {}
};

class LuxuryBody: public Body {
  public:
    LuxuryBody():Body("LuxuryBody", 100) {}
};


class Car {
  protected:
    string name;
    Tire *_t;
    Body *_b;
  public:
    Car(string n):name(n) {}
    void setTire(Tire *t) { _t = t; }
    void setBody(Body *b) { _b = b; }
    void printDetails() {
      cout << "Car : " << name << endl;
      cout << "Tire: " << _t->getName() << ", Presure : " << _t->getPresure() << endl;
      cout << "Body: " << _b->getName() << ", Strength: " << _b->getStrength() << endl; 
    }
};


class CarFactory {
  private:
    //Car *car; //looks it is not needed that's why i commented
  protected:
    virtual Tire* buildTire() = 0;
    virtual Body* buildBody() = 0;
    //Much more product's part could come here
  public:
    virtual Car* buildWholeCar() = 0;
};


class SimpleCarFactory: public CarFactory {
  Tire* buildTire() {
    return new SimpleTire();
  }
  Body* buildBody() {
    return new SimpleBody();
  }

  Car* buildWholeCar() {
    Car *car = new Car("SimpleCar");
    car->setTire(buildTire());
    car->setBody(buildBody());
    return car;
  }
};

class LuxuryCarFactory: public CarFactory {
  Tire* buildTire() {
    return new LuxuryTire();
  }
  Body* buildBody() {
    return new LuxuryBody();
  }

  Car* buildWholeCar() {
    Car *car = new Car("LuxuryCar");
    car->setTire(buildTire());
    car->setBody(buildBody());
    return car;
  }
};


#define SIMPLE_CAR 1
//#define LUXURY_CAR 2

int main() {

#ifdef SIMPLE_CAR
  CarFactory *factory = new SimpleCarFactory;
#endif

#ifdef LUXURY_CAR
  CarFactory *factory = new LuxuryCarFactory;
#endif

  Car *car = factory->buildWholeCar();
  car->printDetails();

  return 0;
}
