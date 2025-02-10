/*A library system allows users to borrow and return books. The system should:
1. Add new books to the collection.
2. Borrow books (check availability).
3. Return books.
4. Display all available books.
Requirements:
 Implement a Book class with attributes: ID, title, author, availability.
 Implement a Library class with:
1. Method to add a book (with unique ID).
2. Method to borrow a book (updates availability).
3. Method to return a book (marks it available).
4. Method to display all available books.
 Store book records dynamically using pointers and DMA.
 Use constructor overloading to initialize books with or without availability status.*/

#include<iostream>
using namespace std;

class Book {
    private:
    int id;
    string title;
    string author;
    bool isAvailable;

    public:
    Book() : id(000), title("title"), author("author"), isAvailable(false) {}

    Book(int id, string title, string author, bool isAvailable)
        : id(id), title(title), author(author), isAvailable(isAvailable) {}

    void setId(int id) {
        this->id = id;
    }

    int getId() const {
        return id;
    }

    void setTitle(string title) {
        this->title = title;
    }

    string getTitle() const {
        return title;
    }

    void setAuthor(string author) {
        this->author = author;
    }

    string getAuthor() const {
        return author;
    }

    void setIsAvailable(bool isAvailable) {
        this->isAvailable = isAvailable;
    }

    bool getIsAvailable() const {
        return isAvailable;
    }
};

class Library {
    private:
    Book *books;
    int noOfBooks;
    public:
    Library():books(nullptr), noOfBooks(0) {}

    ~Library(){
        delete[] books;
    }

    void addBook(int newBookId, string newTitle, string newAuthor) {
        if(noOfBooks > 0){
            for(int i = 0; i < noOfBooks; i++){
                if(newBookId == books[i].getId()){
                    return ;
                }
            }
        }

        Book *tempBooks = new Book[noOfBooks + 1];

        
        for (int i = 0; i < noOfBooks; i++) {
            tempBooks[i].setId(books[i].getId());
            tempBooks[i].setTitle(books[i].getTitle());
            tempBooks[i].setAuthor(books[i].getAuthor());
            tempBooks[i].setIsAvailable(books[i].getIsAvailable());

        }
        tempBooks[noOfBooks].setId(newBookId);
        tempBooks[noOfBooks].setTitle(newTitle);
        tempBooks[noOfBooks].setAuthor(newAuthor);
        tempBooks[noOfBooks].setIsAvailable(true);//if you are adding a book it will be avvailable
        

        delete[] books;
        books = tempBooks;

        noOfBooks++;

    }

    void displayDetails() {
        cout << "Library Details" << endl;
        cout << "===============" << endl;
        for(int i = 0; i < noOfBooks; i++){
            cout << books[i].getId() << endl;
            cout << books[i].getTitle() << endl;
            cout << books[i].getAuthor() << endl;
            books[i].getIsAvailable() ? (cout << "Available") : (cout << "Not Available");
            cout << endl;
        }

        cout << "===============" << endl;
    }

    void borrowBook(int borrowBookId){
        if(noOfBooks > 0){
            for(int i = 0; i < noOfBooks; i++){
                if(borrowBookId == books[i].getId() && books[i].getIsAvailable() == true){
                    books[i].setIsAvailable(false);
                }
            }
        }
    }

    void returnBook(int returnBookId){
        if(noOfBooks > 0){
            for(int i = 0; i < noOfBooks; i++){
                if(returnBookId == books[i].getId() && books[i].getIsAvailable() == false){
                    books[i].setIsAvailable(true);
                }
            }
        }
    }

};

int main() {
    Library l1;

    l1.addBook(1111, "test 1", "author 1");
    l1.addBook(1121, "test 2", "author 2");
    l1.displayDetails();
    l1.borrowBook(1111);
    l1.displayDetails();
    l1.returnBook(1111);
}

