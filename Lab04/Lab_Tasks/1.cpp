/*You are building a student management system. Create a class `Student` to manage student records.
Requirements:
1. Attributes:
 `studentID` (int)
 `name` (string)
 `age` (int)
 `grade` (char)
2. Define a default constructor that initializes `grade` to `'N'` (Not Assigned).
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
 `promoteStudent()`: Upgrades the student's grade (e.g., from 'A' to 'B').
 `isEligibleForScholarship()`: Returns `true` if the student's grade is 'A'.
 `displayDetails()`: Displays the student's details.
5. Create a few `Student` objects and test the methods.*/

#include<iostream>
using namespace std;

class Student {
    private:
    int studentID;
    string name;
    int age;
    char grade;

    public:
    Student() {
        grade = 'N';
    }

    Student(int studentID, string name, int age, char grade) {
        this->studentID = studentID;
        this->name = name;
        this->age = age;
        this->grade = grade;
    }

    void promoteStudent(char newGrade) {
        grade = newGrade;
    }
    
    bool isEligibleForScholarship() {
        if (grade == 'A' || grade == 'a'){
            return true;
        }
        else{
            return false;
        }
    }

    void displayDetails() {
        cout << "Student ID -> " << studentID << endl;
        cout << "Name -> " << name << endl;
        cout << "Age -> " << age << endl;
        cout << "Grade -> " << grade << endl;
    }
};

int main()
{
    Student s1(1234, "name 1", 18, 'B'), s2(9999, "name 2", 28, 'D');
    
    s1.promoteStudent('A');
    s1.displayDetails();
    (s1.isEligibleForScholarship())?cout << "Eligible":cout << "Not Eligible";
    cout << endl;


    
    s2.promoteStudent('D');
    s2.displayDetails();
    (s2.isEligibleForScholarship())?cout << "Eligible":cout << "Not Eligible";
    cout << endl;
    return 0;
}