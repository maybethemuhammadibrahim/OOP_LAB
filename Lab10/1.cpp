/*
1. Define a structure Student with the following fields:
○ int id
○ string name
○ float gpa
2. Prompt the user to enter data for 5 students.
3. Write these records to a file named students.txt using ofstream with ios::out
mode.
4. Then, allow the user to append 1 additional student record using ios::app mode
(open in append mode and write without erasing old content).
5. Finally, read and display all student records from the file using ifstream.
*/
#include <iostream>
#include <fstream>
using namespace std;

struct Student
{
    int id;
    string name;
    float gpa;
};

int main()
{
    ofstream outputFile("output.txt", ios::out | ios::app);
    if (!outputFile)
    {
        cerr << "Error opening file" << endl;
        return 1;
    }
    Student *s;
    int noOfStudents;
    string name;
    int id;
    float gpa;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter ID for student" << i + 1 << endl;
        cin >> id;

        cout << "Enter Name for student" << i + 1 << endl;
        cin >> name;

        cout << "Enter GPA for student" << i + 1 << endl;
        cin >> gpa;

        s = new Student[1];
        s->id = id;
        s->name = name;
        s->gpa = gpa;

        if (outputFile.is_open())
        {
            outputFile << s->id;
            outputFile << "  ";
            outputFile << s->name;
            outputFile << "  ";
            outputFile << s->gpa;
            outputFile << "  ";
            outputFile << "\n";
        }

        delete[] s;
    }

    cout << "Appending new User" << endl;
    cout << "Appending details" << endl;

    cout << "Enter ID for student" << endl;
    cin >> id;

    cout << "Enter Name for student" << endl;
    cin >> name;

    cout << "Enter GPA for student" << endl;
    cin >> gpa;

    s = new Student[1];
    s->id = id;
    s->name = name;
    s->gpa = gpa;

    if (outputFile.is_open())
    {
        outputFile << s->id;
        outputFile << "  ";
        outputFile << s->name;
        outputFile << "  ";
        outputFile << s->gpa;
        outputFile << "  ";
        outputFile << "\n";
    }
    delete[] s;

    if (outputFile.is_open())
    {
        outputFile.close();
        cout << "File Closed!" << endl;
    }

    ifstream readFile("output.txt", ios::in);

    string temp;
    if (readFile.is_open())
    {
        while (!readFile.eof())
        {
            readFile >> temp;
            cout << "Student ID: " << temp << endl;
            readFile >> temp;
            cout << "Student Name: " << temp << endl;
            readFile >> temp;
            cout << "Student GPA: " << temp << endl;
        }
    }

    if (readFile.is_open())
    {
        readFile.close();
        cout << "File Closed!" << endl;
    }
}