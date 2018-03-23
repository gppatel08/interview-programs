//Keys in map is always unique
/*
#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> ages;

    ages["mike"] = 40;
    ages["raj"] = 15;
    ages["rohit"] = 25;
    ages["guru"] = 30;
    ages["Raman"] = 50;

    cout << "Raj : " << ages["raj"] << endl;

    ages["raj"] = 70;

   // cout << "no map key ABCDE : " << ages["ABCDE"] << endl;
    if(ages.find("ABCDE") != ages.end()) {
        cout << "Found Key.." << endl;
    }
    else {
        cout << "Not Found Key.." << endl;
    }

    cout << endl;

    for(map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
        pair<string, int> age = *it;
        cout << age.first << " : " << age.second << endl;
    }

    cout << endl << " ========== without pair ========== " << endl;
    for(map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
        cout << it->first << " : " << it->second << endl;
    }

    return 0;
}

*/


/*
#include <iostream>
#include <map>

using namespace std;

class Person {
    private:
        string name;
        int age;
    public:
        Person(): name(""), age(0){

        }

        Person(string name, int age): name(name), age(age) {

        }

        Person(const Person &p) {
            cout << "copy cponstructor" << endl;
            name = p.name;
            age = p.age;
        }        

        void print() const {
            cout << "Name : " << name << ", Age : " << age << endl;
        }

        bool operator<(const Person &p) const {
            return name < p.name;
        }
};

int main() {
    map<Person, int> people;
    
    //people[0] = Person("Mike", 25);
    //people[1] = Person("Guru", 32);
    //people[2] = Person("Sonu", 40);

    people[Person("Mike", 25)] = 25;
    people[Person("Guru", 32)] = 32;
    people[Person("Guru", 41)] = 41;
    people[Person("Sonu", 40)] = 40;

    //people.insert(make_pair(10, Person("Deepu", 25)));

    for(map<Person, int>::iterator it = people.begin(); it != people.end(); it++) {
        it->first.print();
    }

    return 0;
}

*/

#include <iostream>
#include <map>
using namespace std;

int main() {
    multimap<int, string> lookup;

    lookup.insert(make_pair(30, "Guru"));    
    lookup.insert(make_pair(40, "Sona"));    
    lookup.insert(make_pair(50, "Deepu"));    
    lookup.insert(make_pair(20, "Gopal"));    
    lookup.insert(make_pair(30, "Gpk"));    
    lookup.insert(make_pair(30, "Gp"));    
    lookup.insert(make_pair(30, "Gpp"));    

    for(multimap<int, string>::iterator it = lookup.begin(); it != lookup.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }

    cout << endl;

    for(multimap<int, string>::iterator it = lookup.find(30); it != lookup.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }

    cout << endl;

    pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(30);

    for(multimap<int, string>::iterator it = its.first; it != its.second; it++) {
        cout << it->first << ": " << it->second << endl;
    }

}

/* OUTPUT:
20: Gopal
30: Guru
30: Gpk
30: Gp
30: Gpp
40: Sona
50: Deepu

30: Guru
30: Gpk
30: Gp
30: Gpp
40: Sona
50: Deepu

30: Guru
30: Gpk
30: Gp
30: Gpp
*/
