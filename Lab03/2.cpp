#include <iostream>
#include <conio.h>
using namespace std;

class TollBooth {
    private:
    unsigned int noOfCars;
    double totalMoney;
    public:
    TollBooth(): noOfCars(0) , totalMoney(0) {}

    void payingCar(){
        noOfCars++;
        totalMoney += 0.50;
    }

    void noPayCar(){
        noOfCars++;
    }

    void display(){
        cout << "The Total number of cars passed is " << noOfCars << endl;
        cout << "The Total money is " << totalMoney << endl;
    }

};

int main() {
    TollBooth t1;
    char input;

    cout << "Toll Management System" << endl;
    cout << "======================" << endl;
    cout << "Enter 1, if car has paid toll money" << endl;
    cout << "Enter 0 if car has not paid toll money" << endl;

    while(input != 27){
        cout << "->";
        input = _getch();
        if(input == '1'){
            t1.payingCar();
            cout << "Car payed the toll, updating data" << endl;
        }
        else if(input == '0') {
            t1.noPayCar();
            cout << "Car did'nt pay the toll, updating data" << endl;
        }
        else if(input == '2') {
            cout << "Showing Data" << endl;
            t1.display();
           
        }
        else if(input == 27) {
             cout << "Exiting Program" << endl;
            break;
        }
        else{
            cout << "Unknown Input" << endl;
        }
    } 
    return 0;
}