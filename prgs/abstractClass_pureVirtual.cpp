#include <iostream>
using namespace std;

// Abstract class
class Shape                   
{
    protected:
       float _l;
    public:
       void setData(float l) { _l = l; }
       
       // virtual Function
       virtual float calculateArea() = 0;
};

class Square : public Shape
{
    public:
       float calculateArea() {   return _l*_l;  }
};

class Circle : public Shape
{
    public:
       float calculateArea() { return 3.14*_l*_l; }
};

int main()
{
    Square s;
    Circle c;

    s.setData(10);
    cout<<"Area of square: " << s.calculateArea() << endl ;

    c.setData(20);
    cout << "Area of circle: " << c.calculateArea() << endl;

    return 0;
}
