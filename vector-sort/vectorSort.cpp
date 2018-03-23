// sorting vector through own comp implemented friend function
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Test {
    private:
        int id;
        string name;
    public:
        Test(int id, string name): id(id), name(name) {}
        ~Test() {}
        void print() const { cout << id << ": " << name << endl; }

        /*bool operator<(const Test &t) const {
            return name < t.name;
        }*/

        friend bool comp(const Test &a, const Test &b);
};

bool comp(const Test &a, const Test &b) {
    return a.name < b.name;
}

int main() {
    vector<Test> t;

    t.push_back(Test(10, "ABC"));
    t.push_back(Test(50, "JKL"));
    t.push_back(Test(20, "DEF"));
    t.push_back(Test(40, "GHI"));

    sort(t.begin(), t.end(), comp);

    for(int i=0; i < t.size(); i++) {
        t[i].print();
    }

    return 0;
}
