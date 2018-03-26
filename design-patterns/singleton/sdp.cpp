/*
Singleton Designe Pattern:
==========================
Define a class that has only one instance and provides a gloabl point of access that instance.

Singleton design pattern is a creational design pattern and one of the main design pattern to learn, 
it gives great flexibility over global variables, but this design pattern should be build with good care 
otherwise developer may fall into lots of problem.

And one of the main problem could be concurrency, when two or more threads are trying to access the same object which you created as singleton might end-up corrupting the data. SO one need to be very careful 
which design Singleton Design Pattern.

1. One and Only one instance
2. Global access
3. No Ownership
4. Lazy initialization

Advantage:
1. save Memory - only one is required so why to create so many.
2. Single access point - Logger, database connection
3. Felxibility - Change anytime you want

Usage:
1. Multithreaded - threadpool (create one thread pool of n number of threads)
2. Database application - logging
3. Configuration Settings - game setting, application setting etc.

How to create:
--------------
To create singleton class we must have
 1. static member
 2. private constructor
 3. static function
*/

#include <iostream>
#include <string>

using  namespace std;

class GameSetting {
    static GameSetting* _instance;
    int _brightness;
    int _width;
    int _height;
    GameSetting(): _width(786), _height(1300), _brightness(75) {}

    GameSetting(GameSetting const &);
    void operator=(GameSetting const &);

  public:
    static GameSetting* getInstance() {
      if(_instance == NULL) {
        _instance = new GameSetting();
      }
      return _instance;
    }

    void setWidth(int width) { _width = width; }
    void setHeight(int height) { _height = height; }
    void setBrightness(int brightness) { _brightness = brightness; }

    int getWidth() { return _width; }
    int getHeight() { return _height; }
    int getBrightness() { return _brightness; }
   
    void displaySetting() {
      cout << "Brightness: " << _brightness << endl;
      cout << "Height    : " << _height << endl;
      cout << "Width     : " << _width << endl << endl;
    }
};


GameSetting* GameSetting::_instance = 0;

void someFunction() {
  GameSetting *setting = GameSetting::getInstance();
  setting->displaySetting();
}

int main() {
  GameSetting *setting = GameSetting::getInstance();
  setting->displaySetting();

  setting->setBrightness(100);

  someFunction();

  return 0;
}



