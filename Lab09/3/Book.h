#ifndef BOOK
#define BOOK
#include <iostream>
#include <string>
using namespace std;

class Book {
protected:
string title, author, isbn;
//int test;

public:
Book(string title,string author, string isbn) ;

string getTitle();
string getAuthor();
string getISBN();

};

#endif