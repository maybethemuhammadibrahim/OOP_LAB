#include <iostream>
#include <conio.h>
using namespace std;

class Angle {
    private:
    int degrees;
    float minutes;
    char dirLetter;
    public:
    //constructor
    Angle(): degrees(0), minutes(0), dirLetter(0) {}

    //setters
    void setDegrees(int degrees){
        this->degrees = degrees;
    }
    void setMinutes(float minutes){
        this->minutes = minutes;
    }
    void setDirLetter(char dirLetter){
        this->dirLetter = dirLetter;
    }

    void getInput(){
        int tempD; float tempM; char tempL; bool temp;
        cout << "Enter the degrees " << endl;
        cin >> tempD; setDegrees(tempD);
        cout << "Enter the minutes " << endl;
        cin >> tempM; setMinutes(tempM);
        cout << "Enter the dirLetter " << endl;
        cin >> tempL; setDirLetter(tempL);
    }

    void displayAngle(){
        cout << degrees << "\xF8" << minutes << "'" << dirLetter << "    ";
        if(dirLetter == 'w' || dirLetter == 'W' || dirLetter == 'e' || dirLetter == 'E'){
            cout << "Longitude" << endl;
        }
        if(dirLetter == 'n' || dirLetter == 'N' || dirLetter == 's' || dirLetter == 'S'){
            cout << "Latitude" << endl;
        }
    }
};

int main(){
    Angle a1;
    char input;
    cout << "Angle Management System" << endl;
    cout << "======================" << endl;
    cout << "Enter 1, to change angle" << endl;
    cout << "Enter 2,to display stored angle" << endl;

    while(input != 27){
        cout << "->";
        input = _getch();
        if(input == '1'){
            a1.getInput();
        }
        else if(input == '2'){
            a1.displayAngle();
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
