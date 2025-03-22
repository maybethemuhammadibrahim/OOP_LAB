#include <iostream>
using namespace std;

class Media
{
protected:
    string title, publicationDate, uniqueID, publisher;
    bool isCheckedOut;

public:
    Media(string title, string publicationDate, string uniqueID, string publisher) : title(title), publicationDate(publicationDate), uniqueID(uniqueID), publisher(publisher), isCheckedOut(false) {}

    virtual void displayInfo()
    {
        cout << "Title: " << title << "\nPublication Date: " << publicationDate
             << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher
             << "\nStatus: " << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }

    void checkOut()
    {
        if (!isCheckedOut)
        {
            isCheckedOut = true;
            cout << title << " has been checked out." << endl;
        }
        else
        {
            cout << title << " is already checked out." << endl;
        }
    }

    void returnItem()
    {
        if (isCheckedOut)
        {
            isCheckedOut = false;
            cout << title << " has been returned." << endl;
        }
        else
        {
            cout << title << " was not checked out." << endl;
        }
    }

    string getTitle()
    {
        return title;
    }
    string getPublicationDate()
    {
        return publicationDate;
    }
};

class Book : public Media
{
private:
    string author, ISBN;
    int numberOfPages;

public:
    Book(string title, string publicationDate, string uniqueID, string publisher, string author, string ISBN, int numberOfPages) : Media(title, publicationDate, uniqueID, publisher), author(author), ISBN(ISBN), numberOfPages(numberOfPages) {}

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nPages: " << numberOfPages << endl;
    }
};

class DVD : public Media
{
private:
    string director, rating;
    int duration; // in minutes

public:
    DVD(string title, string publicationDate, string uniqueID, string publisher, string director, int duration, string rating) : Media(title, publicationDate, uniqueID, publisher), director(director), duration(duration), rating(rating) {}

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << " minutes\nRating: " << rating << endl;
    }
};

class CD : public Media
{
private:
    string artist, genre;
    int numberOfTracks;

public:
    CD(string title, string publicationDate, string uniqueID, string publisher, string artist, int numberOfTracks, string genre) : Media(title, publicationDate, uniqueID, publisher), artist(artist), numberOfTracks(numberOfTracks), genre(genre) {}

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nTracks: " << numberOfTracks << "\nGenre: " << genre << endl;
    }
};

class Magazine : public Media
{
private:
    int issueNumber;

public:
    Magazine(string title, string publicationDate, string uniqueID, string publisher, int issueNumber)
        : Media(title, publicationDate, uniqueID, publisher), issueNumber(issueNumber) {}

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "Issue Number: " << issueNumber << endl;
    }
};


void searchMedia(Media mediaList[], int size, string title)
{
    for (int i = 0; i < size; i++)
    {
        if (mediaList[i].getTitle() == title)
        {
            mediaList[i].displayInfo();
            return;
        }
    }
    cout << "Media not found." << endl;
}

void searchMedia(Media mediaList[], int size, string pubDate, bool isByDate)
{
    for (int i = 0; i < size; i++)
    {
        if (mediaList[i].getPublicationDate() == pubDate)
        {
            mediaList[i].displayInfo();
        }
    }
}

int main()
{
    Book book1("The Great Gatsby", "1925", "B1001", "Scribner", "F. Scott Fitzgerald", "9780743273565", 180);
    DVD dvd1("Inception", "2010", "D2001", "Warner Bros.", "Christopher Nolan", 148, "PG-13");
    CD cd1("Thriller", "1982", "C3001", "Epic Records", "Michael Jackson", 9, "Pop");
    Magazine mag1("National Geographic", "2023", "M4001", "NatGeo Publishing", 345);

    cout << "\n--- Displaying Media ---\n";
    book1.displayInfo();
    dvd1.displayInfo();
    cd1.displayInfo();
    mag1.displayInfo();

    cout << "\n--- Checking Out and Returning Items ---\n";
    book1.checkOut();
    book1.returnItem();
    dvd1.checkOut();

    return 0;
}
