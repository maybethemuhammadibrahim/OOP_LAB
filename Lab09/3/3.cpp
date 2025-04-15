/*
Problem: A public library is transitioning from manual record-keeping to a digital system.
Staff need secure access to book details (title, author, ISBN) but must not modify records
directly. The system should separate public interfaces (e.g., searching books) from internal
data handling to prevent accidental data corruption.
Classes and Structure:
• Class Book (Header: Book.h, Implementation: Book.cpp):
o Data Members:
▪ title, author, ISBN (strings): Store book metadata.
o Member Functions:
▪ Constructor to initialize book details.
▪ getTitle(), getAuthor(), getISBN(): Return book properties.

• Class Library (Optional for advanced students):
o Data Members:
▪ A collection (e.g., array/list) of Book objects. 
o Member Functions:
▪ addBook(), removeBook(), searchBook(): Manage the collection.

Flow:
• Define Book in header and source files to separate interface and implementation.
• In main(), create a Book object and display its metadata.
*/

#include "Book.h"
#include <iostream>
//#include "Library.h"
using namespace std;

int main() {
    Book b("Test", "Test","Test");
    cout << b.getAuthor() << endl;
    cout << b.getISBN() << endl;
    cout << b.getTitle();
    cout<<"Testing";
}