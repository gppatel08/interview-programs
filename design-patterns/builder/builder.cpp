/*
Qestion: Why Builder DEsigne Pattern
Ans: Because I want to create an object(plane) with composing other complex objects(bodys, engine) step by step.
I want to create those complex objects step by step (Director will hanle that).

Builder Design Pattern is used when you want step by step creation of object, if builder design pattern is not 
used then you will have to create lots of constructors and that becomes problem, 
that's why we create different builders for different constructions.)
*/

#include <iostream>
using namespace std;

//your end product
class Plane {
    string _plane;
    string _body;
    string _engine;
  public:
    Plane(string planeType):_plane(planeType) {}
    void setEngine(string type) {_engine = type;}
    void setBody(string body) {_body = body;}

    string getEngine() { return _engine;}
    string getBody() { return _body;}

    void show() {
        cout << "Plane Type : " << _plane << endl;
        cout << "Body Type  : " << _body <<  endl;
        cout << "Engine Type: " << _engine << endl << endl; 
    }
};

//PlaneBuilder Abstract class, means all builders should have atleast these methods.
class PlaneBuilder {
  protected:
    Plane *_plane;
  public:
    virtual void getPartsDone() = 0;
    virtual void buildBody() = 0;
    virtual void buildEngine() = 0;
    Plane* getPlane() {return _plane;}
    //virtual ~PLaneBuilder() {}
};

//PlaneBuilder concrete class, knows only how to build Propeller Plane 
class PropellerBuilder : public PlaneBuilder {
  public:
    void getPartsDone() { _plane = new Plane("Propeller Plane");}
    void buildEngine() { _plane->setEngine("Propeller Engine");}
    void buildBody() { _plane->setBody("Propeller Body");}
    //~PropellerBuilder() {delete _plane;}
};

//PlaneBuilder concrete class, knows only how to build jet PLane
class JetBuilder: public PlaneBuilder {
  public:
    void getPartsDone() {_plane = new Plane("Jet Plane");}
    void buildEngine() { _plane->setEngine("Jet Engine"); }
    void buildBody() { _plane->setBody("Jet Body"); }
    //~JetBuilder() { delete _plane;}
};

// Director class defines steps and tells to the builder that build in given order.
class Director{
  public:
    Plane* createPlane(PlaneBuilder *builder) {
      builder->getPartsDone();
      builder->buildBody();
      builder->buildEngine();
      return builder->getPlane();
    }
};


int main() {
  Director dir;
  JetBuilder jb;
  PropellerBuilder pb;

  Plane *jet = dir.createPlane(&jb);
  Plane *pro = dir.createPlane(&pb);

  jet->show();
  pro->show();

  delete jet;
  delete pro;

  return 0;
}
