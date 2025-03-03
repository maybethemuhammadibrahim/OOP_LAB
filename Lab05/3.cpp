#include <iostream>
#include <string>

using namespace std;

struct Register {
    string courseId;
    string courseName;
};

struct Student : Register {
    string studentId;
    string firstName;
    string lastName;
    string cellNo;
    string email;
};

int main() {
    Student students[5];

    for (int i=0; i<5; i++) {
        cout << "Enter details for student " << i+1 << endl;
        
        cout << "Enter course ID: ";
        cin >> students[i].courseId;
        cout << "Enter course name: ";
        cin.ignore(); 
        getline(cin, students[i].courseName);

        cout << "Enter student ID: ";
        cin.ignore(); 
        getline(cin, students[i].studentId);
        cout << "Enter first name: ";
        cin.ignore(); 
        getline(cin, students[i].firstName);
        cout << "Enter last name: ";
        cin.ignore(); 
        getline(cin, students[i].lastName);
        cout << "Enter cell number: ";
        cin.ignore(); 
        getline(cin, students[i].cellNo);
        cout << "Enter email: ";
        cin.ignore(); 
        getline(cin, students[i].email);
        cout << endl;
    }


    cout << "\nStudent Registration Details:" << endl;
    for (int i=0; i<5; i++) {
        cout << "\nStudent " << i + 1 << ":" << endl;
        cout << "Course ID: " << students[i].courseId << endl;
        cout << "Course Name: " << students[i].courseName << endl;
        cout << "Student ID: " << students[i].studentId << endl;
        cout << "First Name: " << students[i].firstName << endl;
        cout << "Last Name: " << students[i].lastName << endl;
        cout << "Cell Number: " << students[i].cellNo << endl;
        cout << "Email: " << students[i].email << endl;
    }

    return 0;
}
