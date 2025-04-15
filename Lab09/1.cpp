/*
A vehicle rental company is expanding its services to include cars, bikes, and
future vehicle types. They need a flexible system to manage daily rates and display vehicle
details without exposing internal calculations. The goal is to ensure new vehicle types (e.g.,
scooters, trucks) can be added seamlessly while maintaining a consistent interface for
customers to view rental options.
Classes and Structure:
• Abstract Class Vehicle:
o Data Members:
▪ model (string): Stores the vehicle’s model name.
▪ rate (double): Stores the daily rental rate.
o Member Functions:
▪ getDailyRate(): Pure virtual function to return the daily rate.
▪ displayDetails(): Pure virtual function to show model and rate.

• Derived Class Car:
o Inherits model and rate from Vehicle.
o Overrides getDailyRate() and displayDetails() to provide car-specific
behavior.
• Derived Class Bike:
o Inherits model and rate from Vehicle.
o Overrides getDailyRate() and displayDetails() to provide bike-specific
behavior.

Flow:
• Create Car and Bike objects.
• Use polymorphism to call displayDetails() and getDailyRate() for each vehicle.
*/
#include <iostream>
using namespace std;

class Vehicle {
    protected:
    string model;
    double rate;//assuming monthly rental rate

    public:
    Vehicle(string model, double rate) : model(model), rate(rate) {
    
    }

    virtual int getDailyRate() = 0;
    virtual void displayDetails() = 0;

};

class Car: public Vehicle {

    public:
    Car(string model, double rate) : Vehicle(model, rate) {}

    int getDailyRate() override {
        return rate;
    }

    void displayDetails() {
        cout << "Car Model: " << model << endl;
        cout << "Daily Rental Rate: " << getDailyRate() << endl;
    }
};

class Bike: public Vehicle {

    public:
    Bike(string model, double rate) : Vehicle(model, rate) {}

    int getDailyRate() override {
        return rate;
    }

    void displayDetails() {
        cout << "Bike Model: " << model << endl;
        cout << "Daily Rental Rate: " << getDailyRate() << endl;
    }
};

int main() {
Bike b1("Honda 215", 40);
Car c1("Honda City", 100);
Vehicle *p;
p->displayDetails();
p->displayDetails();
}