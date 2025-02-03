

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

    //setters
    void setCompany(string company){
        this->company = company;
    }
    void setModel(string model){
        this->model = model;
    }
    void setDisplayResolution(string displayResolution){
        this->displayResolution = displayResolution;
    }
    void setRam(float ram){
        this->ram = ram;
    }
    void setRom(float rom){
        this->rom = rom;
    }
    void setStorage(float storage){
        this->storage = storage;
    }


    // getters
    string getCompany(){
        return company;
    }
    string getModel(){
        return model;
    }
    string getDisplayResolution(){
        return displayResolution;
    }
    float getRam(){
        return ram;
    }
    float getRom(){
        return rom;
    }
    float getStorage(){
        return storage;
    }

    //methods
    void makeAPhoneCall(){
        cout << "Making a phone call" << endl;
    }
    void sendAMessage(){
        cout << "Sending a message" << endl;
    }
    void connectToWifi(){
        cout << "Connecting to wifi" << endl;
    }
    void browseTheInternet(){
        cout << "Browsing the internet" << endl;
    }
    
};

int main() {
    Smartphone s1,s2,s3;
    s1.setCompany("Samsung");
    s1.setModel("s24");
    s1.setDisplayResolution("1080p");
    s1.setRam(4024);
    s1.setRom(10);
    s1.setStorage(128);


    s1.getCompany();
    s1.getModel();
    s1.getDisplayResolution();
    s1.getRam();
    s1.getRom();
    s1.getStorage();


          

}
