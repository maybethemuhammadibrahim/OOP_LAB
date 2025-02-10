#include <iostream>
using namespace std;

class Employee {
    private:
    int employeeID;
    string name;
    string department;
    double salary;

    public:
    Employee() : salary(0.0) {}

    Employee(int employeeID, string name, string department, double salary):employeeID(employeeID),name(name),department(department),salary(salary) {}

    void giveBonus(double amount) {
        salary += amount;
    }

    bool isManager() {
        return department == "Management";
    }

    void displayDetails() {
        cout << "Employee ID -> " << employeeID << endl;
        cout << "Name -> " << name << endl;
        cout << "Department -> " << department << endl;
        cout << "Salary -> " << salary << endl;
    }
};

int main() {
    Employee e1(1001, "Alice", "Management", 75000), e2(1002, "Bob", "Engineering", 60000);

    e1.giveBonus(5000);
    e2.giveBonus(3000);

    cout << "Details of Employee 1:" << endl;
    e1.displayDetails();
    cout << (e1.isManager() ? "Is a Manager" : "Not a Manager") << endl;
    cout << endl;

    cout << "Details of Employee 2:" << endl;
    e2.displayDetails();
    cout << (e2.isManager() ? "Is a Manager" : "Not a Manager") << endl;
    cout << endl;

    return 0;
}
