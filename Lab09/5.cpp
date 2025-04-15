#include <iostream>
using namespace std;

class Activity {
    public:

    virtual double calculateCaloriesBurned() = 0;

};

class Running : public Activity {
    private:
    double distance;//assuming meters
    double time;//assuming minutes

    public:
    Running(double distance = 0,double time = 0) : distance(distance), time(time) {

    }

    double calculateCaloriesBurned() override {
        return distance * time;
    }

};

class Cycling : public Activity {
    private:
    double speed;//assuming kmph
    double time;//assuming minutes

    public:
    Cycling(double speed = 0, double time = 0) : speed(speed), time(time) {}

    double calculateCaloriesBurned() override {
        return speed * time;
    }
};

int main() {
    Running r(10,60); Cycling c(100,1);
    Activity *a;
    
    a = &r;
    a->calculateCaloriesBurned();

    a=&c;
    a->calculateCaloriesBurned();
}
