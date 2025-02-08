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
        int returnHours = ((hours + other.hours) % 12);

        int returnMinutes;
        if((minutes + other.minutes) < 60){
            returnMinutes = (minutes + other.minutes);
        }
        else if((minutes + other.minutes) >= 60){
            returnHours += (minutes + other.minutes) / 60;
            returnMinutes =  (minutes + other.minutes) % 60;
        }
        // int returnMinutes = (minutes + other.minutes);


        int returnSeconds;
        if((seconds + other.seconds) < 60){
            returnSeconds = (seconds + other.seconds);
        }
        else if((seconds + other.seconds) >= 60 && (seconds + other.seconds) <= 3600 ){
            returnMinutes += (seconds + other.seconds) / 60;
            returnSeconds =  (seconds + other.seconds) % 60;
        }
        else if((seconds + other.seconds) >= 3600 ){
            returnHours += (seconds + other.seconds) / 3600;
            returnSeconds =  (seconds + other.seconds) % 3600;
        }
        return Time(returnHours, returnMinutes, returnSeconds);
    }
};

int main(){
    Time t1(1,55,0);
    Time t2(11,5,0);
    Time t3;

    t3 = t1.add(t2);
    cout << "The Sum of two times in the  third object is ";
    t3.displayTime();
    cout << endl;
}
