#include <iostream>
using namespace std;

class Device
{
protected:
    string deviceId;
    string deviceType;
    double powerRating;
    bool status;

public:
    Device(string deviceId = "", string deviceType = "", double powerRating = 0, bool status = false)
        : deviceId(deviceId), deviceType(deviceType), powerRating(powerRating), status(status) {}

    virtual void turnOn()
    {
        if (status == false)
        {
            status = true;
        }
        else
        {
            cout << "Device already turned on" << endl;
        }
    }

    virtual void turnOFF()
    {
        if (status == true)
        {
            status = false;
        }
        else
        {
            cout << "Device already turned off" << endl;
        }
    }

    virtual double calculatePowerUsage(int hours) = 0;
};

class Light : public Device
{
private:
public:
    Light(string deviceId = "", string deviceType = "", double powerRating = 0)
        : Device(deviceId, deviceType, powerRating, false)
    {
    }

    double calculatePowerUsage(int hours) override
    {
        return hours * powerRating;
    }

    // no need to override turnOn() and turnOff()
};

class Fan : public Device
{
private:
    float speedFactor; // on a scale of 1 to 10

public:
    Fan(string deviceId = "", string deviceType = "", double powerRating = 0, float speedFactor = 0)
        : Device(deviceId, deviceType, powerRating, status)
    {
        if (speedFactor > 1 && speedFactor < 10)
        {
            this->speedFactor = speedFactor;
        }
        else
        {
            do
            {
                cout << "Wrong speed value" << endl;
                cout << "Re-Enter Speed Value" << endl;
                cin >> speedFactor;
            } while (speedFactor < 1 && speedFactor > 10);
        }
    }

    double calculatePowerUsage(int hours) override
    {
        return hours * powerRating * speedFactor;
    }

    // no need to override turnOn() and turnOff()
};

class AC : public Device
{
private:
    float currentTemp;
    float desiredTemp;

public:
    AC(string deviceId = "", string deviceType = "", double powerRating = 0, float currentTemp=0.0, float desiredTemp=0.0)
        : Device(deviceId, deviceType, powerRating, false), currentTemp(currentTemp), desiredTemp(desiredTemp) {}

    void turnOn(int setThisTemp)
    {
        if (setThisTemp != currentTemp)
        {
            desiredTemp = setThisTemp;
        }
        else
        {
            cout << "This Temperature has been reached" << endl;
        }
    }

    double calculatePowerUsage(int hours) override
    {
        return (powerRating * hours * (1 - (currentTemp - desiredTemp) / 100));
    }
};

class SecuritySystem : public Device
{
private:
public:
    SecuritySystem(string deviceId = "", string deviceType = "", double powerRating = 0, bool status = false)
        : Device(deviceId, deviceType, powerRating, status) {}

    double calculatePowerUsage(int hours) override
    {

        return hours * powerRating;
    }
};

class SpecialSecurityControls;

class User
{
private:
    string userId;
    string userRole;
    int accessLevel; // 2 if they can, 1 if they cannot
public:
    User(string userId = "", string userRole = "", int accessLevel = 0) : userId(userId), userRole(userRole), accessLevel(accessLevel) {}

    void viewAccessibleDevices(){
        if (accessLevel == 1)
        {
            cout << "You can Access Lights, Fans, and ACs [Non-Admin]" << endl;
        }
        else
        {
            cout << "You can Access Lights, Fans, ACs, and Security Systems [Admin]" << endl;
        }
    }

    void accessSecurityLogs(SpecialSecurityControls &s);
};

class SpecialSecurityControls
{
private:
    bool cameraStatus;          // on or off
    string *intrusionAlerts; // log of 10 latest alerts
    int noOfLogs;
public:
    SpecialSecurityControls(bool cameraStatus = true, string *intrusionlAlerts = nullptr, int noOfLogs = 0) : cameraStatus(cameraStatus), intrusionAlerts(intrusionAlerts), noOfLogs(noOfLogs) {}

    friend void User::accessSecurityLogs(SpecialSecurityControls &s);
};


void User::accessSecurityLogs(SpecialSecurityControls &s)
{
    if (accessLevel == 2)
    {
        cout << "Accessing Admin Information" << endl;
        cout << "Camera Status -> " << (s.cameraStatus ? "ON" : "OFF") << endl;
        for(int i =0 ; i<s.noOfLogs ; i++) {
            cout << s.intrusionAlerts[i] << endl;
        }
    }
    else
    {
        cout << "Access Denied!" << endl;
    }
}

int main()
{
    User user1("U001", "Regular User", 1);
    User user2("U002", "Maintenance Staff", 2);

    Light light1("L001", "LED Light", 10);
    Fan fan1("F001", "Ceiling Fan", 75, 3);
    AC ac1("AC001", "Split AC", 1500, 25);
    SecuritySystem secSys1("S001", "Home Alarm", 100);
    string log[10] = {"log1", "log2"};
    SpecialSecurityControls controlSys(true, log , 2);

    light1.turnOn();
    fan1.turnOn();
    ac1.turnOn(21);
    secSys1.turnOn();

    cout << light1.calculatePowerUsage(5) << endl;
    cout << fan1.calculatePowerUsage(3) << endl;
    cout << ac1.calculatePowerUsage(6) << endl;
    cout << secSys1.calculatePowerUsage(24) << endl;

    user1.viewAccessibleDevices(); // Can see lights, fans, ACs, but NOT security systems
    user2.accessSecurityLogs(controlSys);    // Allowed to view security logs
}
