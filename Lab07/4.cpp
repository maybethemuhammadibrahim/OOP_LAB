#include <iostream>
using namespace std;

class Course
{
private:
    string courseId, courseName, instructor, schedule;
    int credits;

public:
    Course() : courseId("N/A"), courseName("N/A"), instructor("N/A"), schedule("N/A"), credits(0) {}

    Course(string courseId, string courseName, string instructor, string schedule, int credits)
        : courseId(courseId), courseName(courseName), instructor(instructor), schedule(schedule), credits(credits) {}

    Course &operator=(const Course &other)
    {
        if (this != &other)
        { 
            courseId = other.courseId;
            courseName = other.courseName;
            instructor = other.instructor;
            schedule = other.schedule;
            credits = other.credits;
        }
        return *this;
    }

    void displayDetails()
    {
        cout << "Course ID: " << courseId << "\nCourse Name: " << courseName
             << "\nInstructor: " << instructor << "\nSchedule: " << schedule
             << "\nCredits: " << credits << endl;
    }
};

class Person
{
protected:
    string name, id, address, phoneNumber, email;

public:
    Person(string name, string id, string address, string phoneNumber, string email)
        : name(name), id(id), address(address), phoneNumber(phoneNumber), email(email) {}

    virtual void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }

    void updateInfo(string newAddress, string newPhone, string newEmail)
    {
        address = newAddress;
        phoneNumber = newPhone;
        email = newEmail;
    }
};

class Student : public Person
{
private:
    Course coursesEnrolled[5];
    float GPA;
    int enrollmentYear;

public:
    Student(string name, string id, string address, string phoneNumber, string email,
            Course courses[], float GPA, int enrollmentYear)
        : Person(name, id, address, phoneNumber, email), GPA(GPA), enrollmentYear(enrollmentYear)
    {
        for (int i = 0; i < 5; i++)
        {
            coursesEnrolled[i] = courses[i];
        }
    }

    void displayInfo() override
    {
        Person::displayInfo();
        cout << "GPA: " << GPA << "\nEnrollment Year: " << enrollmentYear << "\nCourses: ";
        for (int i = 0; i < 5; i++)
        {
            coursesEnrolled[i].displayDetails();
        }
        cout << endl;
    }
};

class Professor : public Person
{
private:
    string department;
    Course coursesTaught[3];
    float salary;

public:
    Professor(string name, string id, string address, string phoneNumber, string email,
              string department, Course courses[], float salary)
        : Person(name, id, address, phoneNumber, email), department(department), salary(salary)
    {
        for (int i = 0; i < 3; i++)
        {
            coursesTaught[i] = courses[i];
        }
    }

    void displayInfo() override
    {
        Person::displayInfo();
        cout << "Department: " << department << "\nSalary: $" << salary << "\nCourses Taught: ";
        for (int i = 0; i < 3; i++)
        {
            coursesTaught[i].displayDetails();
        }
        cout << endl;
    }
};

class Staff : public Person
{
private:
    string department, position;
    float salary;

public:
    Staff(string name, string id, string address, string phoneNumber, string email,
          string department, string position, float salary)
        : Person(name, id, address, phoneNumber, email), department(department), position(position), salary(salary) {}

    void displayInfo() override
    {
        Person::displayInfo();
        cout << "Department: " << department << "\nPosition: " << position << "\nSalary: $" << salary << endl;
    }
};

int main()
{
    //used AI here to generate dummy data only
    // Creating Course objects
    Course courses[5] = {
        Course("CS101", "Intro to CS", "Dr. Smith", "MWF 9-10 AM", 3),
        Course("MATH201", "Calculus II", "Dr. Brown", "TTh 11-12:30 PM", 4),
        Course("PHY301", "Physics I", "Dr. Green", "MW 2-3:30 PM", 3),
        Course("HIST101", "World History", "Dr. White", "TTh 9-10:30 AM", 3),
        Course("ENG102", "English Composition", "Dr. Black", "MWF 1-2 PM", 3)};

    Course profCourses[3] = {
        Course("CS201", "Data Structures", "Dr. Miller", "MW 10-11 AM", 3),
        Course("CS301", "Algorithms", "Dr. Johnson", "TTh 2-3:30 PM", 3),
        Course("CS401", "Operating Systems", "Dr. Miller", "MWF 3-4 PM", 3)};

    // Creating a Student object
    Student student1("Alice Johnson", "S12345", "123 Elm St", "555-1234", "alice@email.com", courses, 3.8, 2022);

    // Creating a Professor object
    Professor professor1("Dr. Robert Miller", "P56789", "456 Oak St", "555-5678", "robert@email.com", "Computer Science", profCourses, 90000.0);

    // Creating a Staff object
    Staff staff1("Mary Williams", "ST98765", "789 Pine St", "555-9876", "mary@email.com", "Admin", "Registrar", 50000.0);

    // Displaying details
    cout << "---- Student Details ----\n";
    student1.displayInfo();

    cout << "\n---- Professor Details ----\n";
    professor1.displayInfo();

    cout << "\n---- Staff Details ----\n";
    staff1.displayInfo();

    return 0;
}
