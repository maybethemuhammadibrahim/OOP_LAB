#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(string title, string author, string isbn){
this->title = title;
this->author = author;
this->isbn = isbn;}

string Book::getTitle() {
    return title;
}

string Book::getAuthor() {
    return author;
}

string Book::getISBN() {
    return isbn;
}