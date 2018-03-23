/*
//1. Basic Exception

#include <iostream>

using namespace std;

void mightGoWrong(void) {
    bool error1 = false;
    bool error2 = true;

    if(error1) {
        throw "something went wrong error 1 :";
    }
 
    if(error2) {
        throw string("something went wrong error 2 :");
    }
}

int main() {
    try {
        mightGoWrong();
    }
    catch(int e) {
        cout << "Error code: " << e << endl;
    }
    catch(char const *e) {
        cout << "Error Message: " << e << endl;
    }
    catch(string &e) {
        cout << "String Error Message : " << e << endl;
    }

    cout << "still running" << endl;

    return 0;
}
*/

/*
// 2. Standard Exception
#include <iostream>

using namespace std;

class CantGoWrong {
    public:
       CantGoWrong() {

           char *pMemory = new char [9999999999999];
           delete []pMemory;
       }
};


int main() {
    try {
        CantGoWrong wrong;
    }
    catch(bad_alloc &e) {
        cout << "Error Message: " << e.what() << endl;
    }

    cout << "still running." << endl;
    return 0;
}

*/


/*
//3. Custom Exception

#include <iostream>
#include <exception>

using namespace std;

class MyException: public exception {
    public:
          virtual const char* what() const throw() {
              return "something bad happen";
          }
};

class Test {
    public:
        void goesWrong() {
            throw MyException();
        }
};

int main() {
    Test t;

    try {
        t.goesWrong();
    }
    catch(MyException e) {
        cout << e.what() << endl;
    }

    cout << "still running." << endl;
    return 0;
}
*/


// 4. Catching subclass exception
// exception catching order: order of catch should be from subclass exception to exception class 
//like derived class --> base class (at the last base class exception catch should be)

#include <iostream>
#include <exception>

using namespace std;

void goesWrong() {
    bool error1Detected = true;
    bool error2Detected = true;

    if(error1Detected) {
        throw bad_alloc();
    }

    if(error2Detected) {
        throw exception();
    }
}

int main() {
    try {
        goesWrong();
    }
    catch(bad_alloc &e) {
        cout << "catching bad alloc: " << e.what() << endl;
    }
    catch(exception &e) {
        cout << "catching exception: " << e.what() << endl;
    }

    cout << "still running." << endl;
    return 0;
}
