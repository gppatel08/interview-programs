/*
//1. Write Text File
#include <iostream>
#include <fstream>

using  namespace std;

int main() {
    string outFileName = "writeTextFile.txt";
    
    //case 1
    //fstream outFile;
    //outFile.open(outFileName.c_str(), ios::out);
    
    //case 2
    ofstream outFile;
    outFile.open(outFileName.c_str());

    if(outFile.is_open()) {
        outFile << "Hello Guru.!!" << endl;
        outFile << 12345 << endl;
        outFile.close();
    }
    else {
       cout << "Couldn't create file: " << outFileName << endl;
    }

    return 0;
}
*/

/*
// 2. Reading from text file
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string inputFileName = "readFilename.txt";
    
    ifstream inputFile;
    inputFile.open(inputFileName.c_str());

    if(inputFile.is_open()) {
        string line;

        //while(!inputFile.eof()) {
        while(inputFile) {
            //line will have word till before the space terminated
            //Example: "Hello world" will come as only "Hello"
            //inputFile >> line;

            //Example: "Hello world" will come as "Hello world"
            getline(inputFile, line); // will have whole line with \n terminated

            cout << line << endl;
        }

        inputFile.close();
    }
    else {
        cout << "Couldn't open file: " << inputFileName << endl;
    }
    return 0;
}

*/

/*
//3. Formatted output data readed from file
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string filename = "stats.txt";

    ifstream input;
    input.open(filename.c_str());

    if(!input.is_open()) {
        return 1;
    }

    while(input) {
        string line;

        getline(input, line, ':');
        int population;
        input >> population;

        //below is for removing the new line character from each line either way 
        //input.get();
        input >> ws;

        if(!input) {
            break;
        }

        cout << "'" << line << "' -- " << population << endl;
    }

    return 0;
}
*/


/*
//4. Structre and padding in Binary file
#include <iostream>
#include <fstream>

using namespace std;

//Turn off the padding by placing structure definition inbetween push and pop pragma
#pragma pack(push, 1)
struct Person {
    char name[50]; //50 bytes
    int age; //4 bytes
    double weight; // 8 bytes
};
#pragma pack(pop)

int main() {
    // will have size as 64 with padding bytes
    // hence before writing into file need to make padding off
    cout << "size of Person : " << sizeof(Person) << endl;
    return 0;
}
*/


//5. Binary file reading writing
#include <iostream>
#include <fstream>

using namespace std;

//Turn off the padding by placing structure definition inbetween push and pop pragma
#pragma pack(push, 1)
struct Person {
    char name[50]; //50 bytes
    int age; //4 bytes
    double height; // 8 bytes
};
#pragma pack(pop)

int main() {
    string fileName = "test.bin";

    // start -- Writing to the Binary File
    Person someone = {"GPPatel", 32, 5.6};

    ofstream outputFile;
    outputFile.open(fileName.c_str(), ios::binary);

    if(outputFile.is_open()) {
        //outputFile.write((char*)&someone, sizeof(Person));
        outputFile.write(reinterpret_cast<char*>(&someone), sizeof(Person));
        outputFile.close();
    }
    else {
        cout << "couldn't create file : " << fileName;
    }
    // end -- Writing to the Binary File

   
    // start -- Reading the Binary File
    Person someoneElse = {};

    ifstream inputFile;
    inputFile.open(fileName.c_str(), ios::binary);

    if(inputFile.is_open()) {
        inputFile.read(reinterpret_cast<char*>(&someoneElse), sizeof(Person));
        inputFile.close();
    }
    else {
        cout << "couldn't open file : " << fileName;
    }

    cout << someoneElse.name << endl;
    cout << someoneElse.age << endl;
    cout << someoneElse.height << endl;
    // end -- Reading the Binary File

    return 0;
}

