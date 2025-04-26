/*
1. Assume two existing files: chapter1.txt and chapter2.txt. Populate them with some
text before running this.
2. Open chapter1.txt and chapter2.txt using ifstream in read mode.
3. Open book.txt using ofstream in ios::app mode.
4. Read from both files and append the contents sequentially to book.txt.
5. Ensure a newline is added between chapter contents.
6. After writing, open and display book.txt contents to verify concatenation.
*/
#include <iostream>
#include <fstream>
using namespace std;


int main() {
    ifstream chp1("chapter1.txt", ios::in);
    if(!chp1.is_open()){
        cerr << "Error opening Chp 1" << endl;
    }

    ifstream chp2("chapter2.txt", ios::in);
    if(!chp2.is_open()){
        cerr << "Error opening Chp 2" << endl;
    }

    ofstream book("book.txt", ios::app);
    if(!book.is_open()){
        cerr << "Error opening Book" << endl;
    }


    string temp;
    while(getline(chp1, temp)) {
        book << temp;
    }

    book << "\n";

    while(getline(chp2, temp)) {
        book << temp;
    }

    cout << "Contents of book 1 and book 2 successfully merged" << endl;

    if(chp1.is_open()){
        chp1.close();
    }
    if(chp2.is_open()){
        chp2.close();
    }

    if(book.is_open()){
        book.close();
    }

    ifstream bookread("book.txt", ios::in);
    cout << "\nDisplaying contents of the whole Book" << endl;
    if(bookread.is_open()){
        while(getline(bookread, temp)) {
            cout << temp;
            cout << "\n";
        }
    
    }
    if(bookread.is_open()) {
        bookread.close();
    }

}
