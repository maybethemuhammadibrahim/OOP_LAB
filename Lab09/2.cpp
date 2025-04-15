/*
Problem: A homeowner wants to integrate smart lights and thermostats from different
brands into a single app. The system must provide a unified way to turn devices on/off,
adjust settings, and check statuses without requiring users to interact with brand-specific
interfaces. Future devices (e.g., smart locks) should integrate without altering the core
system.
Classes and Structure:
• Abstract Class SmartDevice:
o Member Functions:

▪ turnOn(): Pure virtual function to activate the device.
▪ turnOff(): Pure virtual function to deactivate the device.
▪ getStatus(): Pure virtual function to return the device’s current state.

• Derived Class LightBulb:
o Data Members:
▪ isOn (bool): Tracks if the light is on/off.
▪ brightness (int): Stores brightness level (0-100%).
o Implements turnOn(), turnOff(), and getStatus() for light control.
• Derived Class Thermostat:
o Data Members:
▪ isOn (bool): Tracks if the thermostat is active.
▪ temperature (double): Stores the current temperature setting.
o Implements turnOn(), turnOff(), and getStatus() for temperature control.

Flow:
• Create LightBulb and Thermostat objects.
• Turn devices on/off and display their statuses.
*/
#include <iostream>
using namespace std;

class SmartDevice {
    public:

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void getStatus() = 0;

};

class Light : public SmartDevice {
    protected:
    bool isOn;
    int brightness;

    public:
    Light(bool isOn = false, int brightness = 0) : isOn(isOn) {
        if(brightness>0 && brightness<100){
            this->brightness = brightness;
        }
        else{
            cout << "Wrong Brightness entered" << endl;
        }
    }

    void turnOn() override{
        if(isOn) {
            cout << "Light already turned on" << endl; 
        }
        else {
            isOn = true;
        }
    }

    void turnOff() override{
        if(!isOn) {
            cout << "Light already turned off" << endl;
        }
        else {
            isOn = false;
        }
    }

    void getStatus() override{
        cout << "Light is turned ";
        if(isOn){
            cout << "On, with " << brightness << endl;
        }
        else{
            cout << "Off" << endl;
        }
    }
};


class Thermostat : public SmartDevice {
    protected:
    bool isOn;
    int temperature;

    public:
    Thermostat(bool isOn = false, int temperature = 0) : isOn(isOn), temperature(temperature) {
        
    }

    void turnOn() override{
        if(isOn) {
            cout << "Thermostat already turned on" << endl; 
        }
        else {
            isOn = true;
        }
    }

    void turnOff() {
        if(!isOn) {
            cout << "Thermostat already turned off" << endl;
        }
        else {
            isOn = false;
        }
    }

    void getStatus() override{
        cout << "Thermostat is turned ";
        if(isOn){
            cout << "On, and its temperature is " << temperature << endl;
        }
        else{
            cout << "Off" << endl;
        }
    }
};
int main() {
    Light l(true, 80);
    Thermostat t(false, 100);
    SmartDevice *s;
    
    //For Light
    s = &l;
    s->getStatus();
    s->turnOff();
    s->getStatus();

    //For Thermostat
    s = &t;
    s->getStatus();
    s->turnOn();
    s->getStatus();

}