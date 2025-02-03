#include <iostream>
#include <conio.h>
using namespace std;

class Angle {
    private:
    int degrees;
    float minutes;
    char dirLetter;
    bool lat_long;
    public:
    //constructor
    Angle(): degrees(0), minutes(0), dirLetter(0), lat_long(0) {}

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
    void set_lat_long(bool lat_long){
        this->lat_long = lat_long;
    }

    void getInput(){
        int tempD; float tempM; char tempL; bool temp;
        cout << "Enter the degrees " << endl;
        cin >> tempD; setDegrees(tempD);
        cout << "Enter the minutes " << endl;
        cin >> tempM; setMinutes(tempM);
        cout << "Enter the dirLetter " << endl;
        cin >> tempL; setDirLetter(tempL);
        // cout << "Enter 1 for Latitude coords/Enter 0 for Longitude coords" << endl;
        // cin >> temp; set_lat_long(tempD);
    }

    void displayAngle(){
        cout << degrees << "\xF8" << minutes << "'" << dirLetter << "    ";
        cout << endl;
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