/*
  C++ has in its definition a way to represent sequence of characters as an object of class. This class is called std:: string. 
  String class stores the characters as a sequence of bytes with a functionality of allowing access to single byte character.

  1. A character array is simply an array of characters can terminated by a null character. 
     A string is a class which defines objects that be represented as stream of characters.

  2. Size of the character array has to allocated statically, more memory cannot be allocated at run time if required. 
     Unused allocated memory is wasted in case of character array. 
            
     In case of strings, memory is allocated dynamically. More memory can be allocated at run time on demand. 
     As no memory is preallocated, no memory is wasted.

  3. There is a threat of array decay in case of character array. As strings are represented as objects, no array decay occurs.

  4. Implementation of character array is faster than std:: string. 
     Strings are slower when compared to implementation than character array.

  5. Character array do not offer much inbuilt functions to manipulate strings. 
     String class defines a number of functionalities which allow manifold operations on strings.

Operations on strings:
======================

A. Input Functions
------------------
      1. getline() :- This function is used to store a stream of characters as entered by the user in the object memory.

      2. push_back() :- This function is used to input a character at the end of the string.

      3. pop_back() :- Introduced from C++11(for strings), this function is used to delete the last character from the string.

B. Capacity Functions
---------------------
     4. capacity() :- This function returns the capacity allocated to the string, which can be equal to or more than the size 
                      of the string. Additional space is allocated so that when the new characters are added to the string, 
                      the operations can be done efficiently.

     5. resize() :- This function changes the size of string, the size can be increased or decreased.

     6.shrink_to_fit() :- This function decreases the capacity of the string and makes it equal to its size. 
                          This operation is useful to save additional memory if we are sure that no further addition of 
                          characters have to be made.

C. Iterator Functions
---------------------
     7. begin() :- This function returns an iterator to beginning of the string.

     8. end() :- This function returns an iterator to end of the string.

     9. rbegin() :- This function returns a reverse iterator pointing at the end of string.

     10. rend() :- This function returns a reverse iterator pointing at beginning of string.

D. Manipulating Functions
-------------------------
     11. copy(“char array”, len, pos) :- This function copies the substring in target character array mentioned in its arguments. 
                  It takes 3 arguments, target char array, length to be copied and starting position in string to start copying.

     12. swap() :- This function swaps one string with other.

*/

#include<iostream>
#include<string> // for string class
using namespace std;

int main()
{
    // Declaring string
    string str;
 
    // Taking string input using getline() "geeksforgeek" in giving output
    getline(cin,str);
 
    // Displaying string
    cout << "The initial string is : ";
    cout << str << endl;
 
    // Using push_back() to insert a character at end pushes 's' in this case
    str.push_back('s');
 
    // Displaying string
    cout << "The string after push_back operation is : ";
    cout << str << endl;
 
    // Using pop_back() to delete a character from end pops 's' in this case
    str.pop_back();
 
    // Displaying string
    cout << "The string after pop_back operation is : ";
    cout << str << endl;

    // Resizing string using resize()
    str.resize(13);
 
    // Displaying string
    cout << "The string after resize operation is : ";
    cout << str << endl;
 
    // Displaying capacity of string
    cout << "The capacity of string is : ";
    cout << str.capacity() << endl;
 
    // Decreasing the capacity of string using shrink_to_fit()
    str.shrink_to_fit();
 
    // Displaying string
    cout << "The new capacity after shrinking is : ";
    cout << str.capacity() << endl;
 
    // Initializing string`
    string str1 = "Guru Prasad Patel";
 
    // Declaring iterator
    std::string::iterator it;
 
    // Declaring reverse iterator
    std::string::reverse_iterator it1;
 
    // Displaying string
    cout << "The string using forward iterators is : ";
    for (it=str1.begin(); it!=str1.end(); it++)
      cout << *it;
    cout << endl;
 
    // Displaying reverse string
    cout << "The reverse string using reverse iterators is : ";
    for (it1=str1.rbegin(); it1!=str1.rend(); it1++)
      cout << *it1;
    cout << endl;

    // Declaring character array
    char ch[80];
 
    // using copy() to copy elements into char array copies "Guru Prasad Patel"
    str1.copy(ch,13,0);

    // Diplaying char array
    cout << "The new copied character array is : ";
    cout << ch << endl << endl;
 
    // Declaring 2nd string
    string str2 = "Gopal Krishna Patel";

    // Displaying strings before swapping
    cout << "The 1st string before swapping is : ";
    cout << str1 << endl;
    cout << "The 2nd string before swapping is : ";
    cout << str2 << endl;
 
    // using swap() to swap string content
    str1.swap(str2);
 
    // Displaying strings after swapping
    cout << "The 1st string after swapping is : ";
    cout << str1 << endl;
    cout << "The 2nd string after swapping is : ";
    cout << str2 << endl;

    return 0;
 
}
