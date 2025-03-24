#include <iostream>
using namespace std;


class Device{
    protected:
    string deviceId;
    string deviceType;
    double powerRating;
    bool status;

    public:
    Device(string deviceId = "", string deviceType = "",double powerRating = 0,bool status = false) 
        : deviceId(deviceId), deviceType(deviceType), powerRating(powerRating), status(status) {}

    virtual void turnOn() {
        if(status = false) {
            status = true;
        }
        else {
            cout << "Device already turned on" << endl;
        }
    }

    virtual void turnOFF() {
        if(status = true) {
            status = false;
        }
        else {
            cout << "Device already turned on" << endl;
        }
    }

    virtual double calculatePowerUsage(int hours) = 0;
     
};

class Light : public Device {
    private:

    public:
    Light(string deviceId = "", string deviceType = "",double powerRating = 0,bool status = false) 
        : Device(deviceId, deviceType, powerRating, status) {}

    double calculatePowerUsage(int hours) override {
        return hours*powerRating;
    }



};

class Fan : public Device {
    private:
    float speedFactor;//on a scale of 0 to 1.0

    public:
    Fan(string deviceId = "", string deviceType = "",double powerRating = 0,bool status = false, float speedFactor=0) 
        : Device(deviceId, deviceType, powerRating, status) {
            if(speedFactor>0.0 && speedFactor<1.0) {
                this->speedFactor = speedFactor;
            }
            else {
                cout << "Wrong speed value" << endl;
            }
        }

    double calculatePowerUsage(int hours) override {
        return hours*powerRating*speedFactor;
    }

    

};

class AC : public Device {
    private:
    float currentTemp;
    float desiredTemp;

    public:
    AC(string deviceId = "", string deviceType = "",double powerRating = 0,bool status = false, float currentTemp, float desiredTemp) 
        : Device(deviceId, deviceType, powerRating, status), currentTemp(currentTemp) , desiredTemp(desiredTemp) {}

    void turnOn(int setThisTemp) {
        if(setThisTemp != currentTemp) {
            desiredTemp = setThisTemp;
        }
        else {
            cout << "This Temperature has been reached" << endl;
        }
    }

    double calculatePowerUsage(int hours) override {
        return (powerRating * hours *(1 -(currentTemp - desiredTemp)/ 100));
    }  

};

class SecuritySystem : public Device {
    private:

    public:
     SecuritySystem(string deviceId = "", string deviceType = "",double powerRating = 0,bool status = false)
        : Device(deviceId, deviceType, powerRating, status) {}

    double calculatePowerUsage(int hours) override {

        return hours*powerRating;
    }   
};

class SpecialSecurityControls
class User {
    private:
    string userId;
    string  userRole;
    int accessLevel;//2 if they can, 1 if they cannot
    public:

    void viewAccesssibleDevices() {
        if(accessLevel==1) {
            cout << "You can Access Lights, Fans ,and ACs" << endl;
        }
        else{
            cout << "You can Access Lights, Fans, ACs, and Security Systems" << endl;
        }
    }
};

int main() {

}
