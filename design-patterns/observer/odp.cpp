/*
Observer Design Pattern(ODP):-
------------------------------
Observer design pattern is a Behavioral pattern and one of the main design pattern to study. I have seen this design pattern widely used in game developments because there depending on one objects state there could be lots of things happening simultaneously.

The idea is there will be an object(subject) and it will keep changing its state and you want to 
perform operations depending on its state so you will create observers and they will keep on 
observing the state of the object(subject) and depending on the state of object they will take 
respective actions.

Defines a one-to-many dependency between objects so that when one object changes state, all its
dependents are notified and updated autometically.

int position;
List Observers;

setPosition(value) {
  position = value;
  Notify();
}

Notify() {
  //Call all O	bservers;
}
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Car {
    int position;
    std::vector<class Observer*> observerList;
  public:
    int getPosition() { return position; }
    void setPosition(int newPosition) {
      position = newPosition;
      notify();
    }
    void attach(Observer *obs) {
      observerList.push_back(obs);
    }
    void detach(Observer *obs) {
      observerList.erase(std::remove(observerList.begin(), observerList.end(), obs),observerList.end());
    }

    void notify();

    /*void notify() {
      for(int i = 0; i < observerList.size(); ++i) {
        observerList[i]->update();
      }
    }*/
};

class Observer {
    Car *_car;
  public:
    Observer(Car *car) {
      _car = car;
      _car->attach(this);
    }
    virtual void update() = 0;

  protected:
    Car* getCar() { return _car; }
};

void Car::notify() {
  for(int i = 0; i < observerList.size(); ++i) {
    observerList[i]->update();
  }
}

class LeftObserver: public Observer {
  public:
    LeftObserver(Car *car): Observer(car) {}
    void update() {
      int pos = getCar()->getPosition();
      if(pos<0) {
        cout << "Left side." << endl;
      }
    }
};

class RightObserver: public Observer {
  public:
    RightObserver(Car *car): Observer(car) {}
    void update() {
      int pos = getCar()->getPosition();
      if(pos>0) {
        cout << "Right side." << endl;
      }
    }
};

class MiddleObserver: public Observer {
  public:
    MiddleObserver(Car *car): Observer(car) {}
    void update() {
      int pos = getCar()->getPosition();
      if(pos==0) {
        cout << "Running in Middle side." << endl;
      }
    }
};


int main() {
  Car *car = new Car();
  
  LeftObserver leftObserver(car);
  RightObserver rightObserver(car);
  MiddleObserver middleObserver(car);

  cout << "Hit left right button to drivae a car!! and press Esc button to close" << endl;
  char pressButton;
  bool breakLoop = false;

  // l(left) <--- c(center) ---> r(right)  (b - break)

  while(breakLoop == false)
  {
    cin >> pressButton;

    switch(pressButton) {
      case 108: //press for left button
        car->setPosition(-1);
        break;
      case 99: //press for center
        car->setPosition(0);
        break;
      case 114: //press for right button
        car->setPosition(1);
        break;
      case 98: //b -> press for break
        breakLoop = true;
        break;
      default:
        cout << "please drive carefully.!!" << endl;
        break;
    }
  }

  cout << "Byeeee...!!" << endl;
  return 0;
}
