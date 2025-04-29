#include <iostream>
#include <exception>
using namespace std;


class InvalidValueException : public exception{
    public:

    const char* what() const noexcept override {
        return "Age cannot be negative or greater than 120";
    }
};



void validateAge(int age) {
    if(age>120 || age<0){
        throw InvalidValueException();
    }
}

int main() {

int age;
bool valid = false;

do{
    try{
    cout << "\nEnter age: ";
    cin >> age;
    validateAge(age);
    valid = true;
} catch (const exception& error) {
    cout << "Error: " << error.what();
} catch (...) {
    cout << "An unknown error occurred.\n";
}
}while(!valid);

cout << "Age successfully Entered" << endl;



}
