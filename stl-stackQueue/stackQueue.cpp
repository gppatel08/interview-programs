#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Test {
    private:
        string name;
    public:
        Test(string name): name(name) {}
        ~Test() { /*cout << "Object Test Destroyed.!" << endl;*/ }
        void print() const { cout << "Name : " << name << endl; } 

};

int main() {
    stack<Test> testStack;
    
    testStack.push(Test("Mike"));
    testStack.push(Test("Guru"));
    testStack.push(Test("Deepu"));
    testStack.push(Test("Sona"));


    while(testStack.size() > 0) {
        Test &t = testStack.top();
        t.print();
        testStack.pop();
    }

    /* 
    // This is invalid code!
    Test &test = testStack.top();
    testStack.pop(); //object is destroyed when poped and 
    test.print(); //References referes to the destroyed object
    */

    /* 
    //This is Valid Code.!
    Test &test = testStack.top();
    test.print();
    testStack.pop();

    Test &test1 = testStack.top();
    test1.print();
    testStack.pop();
    */


    cout << " Queue ---- " << endl;

    queue<Test> testQueue;

    testQueue.push(Test("Mike"));
    testQueue.push(Test("Guru"));
    testQueue.push(Test("Deepu"));
    testQueue.push(Test("Sona"));

    testQueue.back().print();

    cout << endl;

    while(testQueue.size() > 0) {
        Test &t = testQueue.front();
        t.print();
        testQueue.pop();
    }

    return 0;
}
