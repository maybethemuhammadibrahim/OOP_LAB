/*You are building a car rental system. Create a class `Car` to manage cars available for rent.
Requirements:
1. Attributes:
 `carID` (int)
 `model` (string)
 `year` (int)
 `isRented` (bool)
2. Define a default constructor that initializes `isRented` to `false`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:

 `rentCar()`: Marks the car as rented.
 `returnCar()`: Marks the car as available.
 `isVintage()`: Returns `true` if the car's year is before 2000.

5. Create a few `Car` objects and test the methods.*/

#include<iostream>
using namespace std;

class Car {
    private:
    int carId;
    string model;
    int year;
    bool isRented;

    public:
    Car():isRented(false) {}
    Car(int carId, string model, int year, bool isRented):carId(carId), model(model), year(year), isRented(isRented) {}

    void rentCar() {
        isRented = true;
    }

    void returnCar() {
        isRented = false;
    }

    bool isVintage() {
        if(year < 2000) {
            return true;
        }
        else{
            return false;
        }
    }

    void displayDetails() {
    cout << "Car ID: " << carId << endl;
    cout << "Model: " << model << endl;
    cout << "Year: " << year << endl;
    cout << "Status: " << (isRented ? "Rented" : "Available") << endl;
    cout << "Vintage: " << (isVintage() ? "Yes" : "No") << endl;
    }
};

int main() {
    Car c1(1111, "model1", 2010, false), c2(1112, "model2", 1990, false);
    c1.rentCar();
    c1.displayDetails();
    c2.displayDetails();
    c2.rentCar();
    c2.displayDetails();
    c1.returnCar();
    c1.displayDetails();
}
