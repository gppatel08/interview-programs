
//list is a singly link list in which element can be added in begining or end or middle

#include<iostream>
#include<list>

using namespace std;

int main() {
    list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);
    numbers.push_front(0);

    list<int>::iterator it=numbers.begin();
    it++;
    numbers.insert(it, 20);

    cout << "Element : " << *it << endl;
    
    list<int>::iterator eraseit=numbers.begin();
    eraseit++;
    eraseit = numbers.erase(eraseit);
    cout << "Erase: " << *eraseit << endl;

    for(list<int>::iterator it=numbers.begin(); it != numbers.end();) {
        if(*it == 2) {
            numbers.insert(it, 1234);
        }

        // it++ is removed from the for loop line  because of below code
        if(*it == 1) {
            it = numbers.erase(it);
        }
        else {
            it++;
        }
    }
    for(list<int>::iterator it=numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}

