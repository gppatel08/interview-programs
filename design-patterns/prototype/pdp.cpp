/*
Prototype Design Pattern:-
--------------------------
Prototype design pattern is a Creational Design Pattern and its good if you have this design pattern in 
your tool box specially when you are team lead or project manager. I have seen this design pattern 
widely used in game developments and my example also shows that.

The idea is instead of creating costly (time) object again and again you keep registry of such objects 
and take from the registry when ever those objects are needed but still there are lots of things involved.

Intent:-
--------
1. Creating an object is expensive operation than copy an object.
2. All objects Initial state is common and takes time to build.
3. Composition, Creation and Representation of objects should be decoupled from the system.
4. Hide the complexity of creating new instance from the user.
5. Which classes to create are specified at runtime.

Downsides:-
-----------
1. Copy!!! [shallow/deep]
2. Copying an object can be complicated.
3. Circular references class can not be cloned.
4. Over use of this might affect the performance.

Bullet Example:
---------------
In Games, guns fire bullets, but before it come out from the gun it needs to be prepared.

           <------ common for each --------->
	b1 ==================================---------
	b2 ==================================+++++++++
	b3 ==================================#########
	b4 ==================================%%%%%%%%%
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>

using namespace std;

/* Bullet is the base prototype */
class Bullet {
  protected:
    string _bulletName;
    float _speed;
    float _firePower;
    float _damagePower;
    float _direction;
  public:
    Bullet() {}
    Bullet(string bulletName, float speed, float firePower, float damagePower)
                : _bulletName(bulletName), _speed(speed), _firePower(firePower), _damagePower(damagePower) {}
    virtual ~Bullet() {}
    virtual unique_ptr<Bullet> clone() = 0;
    void fire(float direction) {
      _direction = direction;
      cout << "Name        : " << _bulletName << endl
           << "Speed       : " << _speed << endl
           << "FirePower   : " << _firePower << endl
	   << "DamagePower : " << _damagePower << endl 
	   << "Direction   : " << _direction << endl << endl; 
    }
};


/* SimpleBullet is a Concrete Prototype*/
class SimpleBullet: public Bullet {
  public:
    SimpleBullet(string bulletName, float speed, float firePower, float damagePower): 
          Bullet(bulletName, speed, firePower, damagePower) {}

    unique_ptr<Bullet> clone() override {
      return make_unique<SimpleBullet>(*this);
    }
};

/* GoodBullet is a Concrete Prototype*/
class GoodBullet: public Bullet {
  public:
    GoodBullet(string bulletName, float speed, float firePower, float damagePower): 
          Bullet(bulletName, speed, firePower, damagePower) {}

    unique_ptr<Bullet> clone() override {
      return make_unique<GoodBullet>(*this);
    }
};

/* Opeque Bullet type, avoids exposing concrete implementation */
enum BulletType {
  SIMPLE,
  GOOD
};

/* BulletFactory is the client */
class BulletFactory {
  private:
    unordered_map<BulletType, unique_ptr<Bullet>, hash<int> > m_Bullets;
  public:
    BulletFactory() {
      m_Bullets[SIMPLE] = make_unique<SimpleBullet>("Simple Bullet", 50, 75, 75);
      m_Bullets[GOOD]   = make_unique<GoodBullet>("Good Bullet", 75, 100, 100);
    }

    unique_ptr<Bullet> createBullet(BulletType bType) {
      return m_Bullets[bType]->clone();
    }
};


int main() {
  BulletFactory bulletFactory;

  auto bullet = bulletFactory.createBullet(SIMPLE);
  bullet->fire(90);

  bullet = bulletFactory.createBullet(GOOD);
  bullet->fire(100);

  bullet = bulletFactory.createBullet(GOOD);
  bullet->fire(95);

  bullet = bulletFactory.createBullet(SIMPLE);
  bullet->fire(92);

  return 0;
}
