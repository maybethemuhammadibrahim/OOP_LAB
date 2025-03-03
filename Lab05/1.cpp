/*
Create a class called Square with the following attributes:
• sideLength – float variable
• area – float variable
• allareas – static float variable
Create the following methods for your class:
• Constructors (default and parameterized (only takes sideLength as input))
• Function to calculate area, the calculated area should always be added to the allareas
variable each time an area is calculated. (assume it’s called only once for each object)
• Getters and Setters for all variables
In your main functions create 3 Squares with different sideLength. Call the area method for each of
those Square objects. After each time the area method is called, call that square’s getters for area and
allareas to display the updated values.
*/

#include <iostream>
using namespace std;

class Square {
    private:
    float sideLength;
    float area;
    
    public:
    static float allAreas;
    Square() : sideLength(0) {}

    Square(float sideLength) : sideLength(sideLength) {}

    float getSideLength() const{
        return sideLength;
    }

    float getArea() const{
        return area;
    }

    static float getAllAreas() {
        return allAreas;
    }

    void setSideLength(const float length) {
        this->sideLength = length;
    }

    void setArea(const float area) {
        this->area = area;
    }

    void incrementAllAreas(const float area) {
        this->allAreas += area;
    }

    void calcArea() {
        area = sideLength*sideLength;
        allAreas += area;
        // incrementAllAreas(area);
    }

};

float Square::allAreas = 0;

int main(){
    Square s[3] = {(20),(10),(15)};
   for(int i =0;i<3;i++) {
    s[i].calcArea();
    cout << s[i].getArea() << endl;
   }
   cout << Square::getAllAreas() << endl;
   
}