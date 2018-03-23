#include <iostream>
#include <set>

using namespace std;

class Test {
    private:
        int id;
        string name;

    public:
        Test(int id, string name): id(id), name(name) { }
        void print() const {
            cout << id << ": " << name << endl;
        }

        bool operator<(const Test &t) const {
            return name < t.name;
        }
};


int main() {
    set<int> numbers;

    numbers.insert(10);
    numbers.insert(30);
    numbers.insert(20);
    numbers.insert(70);
    numbers.insert(40);

    for(set<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }

    set<int>::iterator itFind = numbers.find(80);
    if(itFind != numbers.end()) {
        cout << "Found: " << *itFind << endl;
    }

    if(numbers.count(80)) {
        cout << "Number Found." << endl;
    }
    else {
        cout << "Not Found" << endl;
    }


    cout << endl;

    set<Test> tests;
    tests.insert(Test(10, "GP"));
    tests.insert(Test(40, "Sona"));
    tests.insert(Test(30, "Deepu"));
    tests.insert(Test(20, "Gopal"));
    tests.insert(Test(50, "Guru"));

    for(set<Test>::iterator it = tests.begin(); it != tests.end(); it++) {
        it->print();
    } 
    return 0;
}

