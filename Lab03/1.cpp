#include <iostream>
using namespace std;

class Time {
    private:
    int hours, minutes, seconds;

    public:
    //constructors
    Time(): hours(0), minutes(0), seconds(0) {}
        
    Time(int hours, int minutes, int seconds): hours(hours), minutes(minutes), seconds(seconds)  {}


    //Display method
    void displayTime(){
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    //add method
    Time add(const Time& other) {
        int returnHours = (hours + other.hours);
        int returnMinutes = (minutes + other.minutes);
        int returnSeconds = (seconds + other.seconds);
        return Time(returnHours, returnMinutes, returnSeconds);
    }
};

int main(){
    Time t1(2,2,40);
    Time t2(3,3,20);
    Time t3;

    t3 = t1.add(t2);
    cout << "The Sum of two times in the  third object is ";
    t3.displayTime();
    cout << endl;
}