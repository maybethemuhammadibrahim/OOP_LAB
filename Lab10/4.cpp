/*
Write the sentence "C++ is a powerful programming language." to a file named
info.txt using ofstream in ios::out mode.
2. Reopen the file using fstream with both ios::in | ios::out modes.
3. Display the initial position of get pointer using tellg() and put pointer using tellp().
4. Use seekg(6) to move the read pointer to the word "powerful" and read the word
from there.
5. Use seekp(6) to move the write pointer to the same position, and overwrite
"powerful" with "dynamic" (same length).
6. Use tellg() and tellp() again to show the new pointer positions.
7. Display the updated content of the file.
*/
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string temp;
    ofstream file("info.txt",ios::out | ios::trunc);
    if(!file.is_open()){
        cout << "Error opening file" << endl;
    }

    file << "C++ is a powerful programming language.\n";
    
    if(file.is_open()) {
        file.close();
    }

    fstream file2("info.txt", ios::in | ios::out | ios::binary);
    if(!file2.is_open()){
        cout << "Error opening file" << endl;
    }
    streampos pos;
    pos = file2.tellp();
    cout << "Current position of input pointer: " << pos << endl;
    pos = file2.tellg();
    cout << "Current position of read pointer: " << pos << endl;

    file2.seekg(9);
    file2 >> temp;
    cout << "The word at the 9th pointer position is " << temp << endl;

    file2.seekp(9);
    temp = "dynamic_";//adjusting character length
    file2 << temp;
    cout << "Wrote dynamic in place of powerful \n";

    pos = file2.tellp();
    cout << "Current position of input pointer: " << pos << endl;
    pos = file2.tellg();
    cout << "Current position of read pointer: " << pos << endl;

    if(file2.is_open()) {
        file2.close();
    }
}
