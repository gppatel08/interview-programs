
//Vector is resizeable array in c++
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> str;

    str.push_back("one");
    str.push_back("two");
    str.push_back("three");

    cout << "THrough loop" << endl;
    for(int i=0; i < str.size(); i++) {
        cout << str[i] << endl;
    }

    cout << "Through iterator look vector" << endl;
    for(vector<string>::iterator it = str.begin(); it != str.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}
*/

//Capacity remain un-changed, but size can be resized any time
//capacity can be changed with reserve method
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<double> numbers(20);
    cout << "Size: " << numbers.size() << endl;

    int capacity = numbers.capacity();
    cout << "Capacity: " << capacity << endl;

    for(int i =0; i < 10000; i++) {
        if(numbers.capacity() != capacity) {
            capacity = numbers.capacity();
            cout << "Capacity: " << capacity << endl;
            
        }
        numbers.push_back(i);
    }

    numbers.resize(20);
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;

    //capacity can be changed with reserve method
    cout << "capacity can be changed with reserved method: " << endl;
    numbers.reserve(200000);
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;

    return 0;
}
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector< vector<int> > grid(3, vector<int>(4,7));
    
    grid[1].push_back(8);

    for(int row=0; row < grid.size(); row++) {
        for(int col=0; col < grid[row].size(); col++) {
            cout << grid[row][col] << flush;
        }
        cout << endl;
    }
    return 0;
}

/*
OUTPUT:
7777
77778
7777
*/
