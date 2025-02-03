/*
Create a class called Smartphone with the following attributes:
 Company
 Model
 Display Resolution
 RAM
 ROM
 Storage

Create getter and setter methods for your attributes. A smartphone has some specific actions that it can perform.
For example:
1. Make a phone call
2. Send a message
3. Connect to the wifi
4. Browse the internet

Create different smartphone objects. Set their attributes using the setter functions and display their attributes after
using the getter functions to fetch the attributes.
*/

#include <iostream>
using namespace std;

class Smartphone {
    private:
    string company;
    string model;
    string displayResolution;
    float ram;
    float rom;
    float storage;

    public:
    Smartphone(): company("no-data"), model("no-data"), displayResolution("no-data"), ram(0), rom(0), storage(0) {}

    void getCompany(string company){
        this->company = company;
    }
    void getModel(string model){
        this->model = model;
    }
    void getDisplayResolution(string displayResolution){
        this->company = company;
    }
    void getCompany(string company){
        this->company = company;
    }
    void getCompany(string company){
        this->company = company;
    }
    void getCompany(string company){
        this->company = company;
    }
};

int main() {

}
