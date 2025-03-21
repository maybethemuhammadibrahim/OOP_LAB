#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.142;

struct Coordinates
{
    int x;
    int y;
};

class Shape
{
private:
    Coordinates position;
    string color;
    float borderThickness;

public:
    Shape(Coordinates position = {0, 0}, string color = "null", float borderThickness = 0.0) : position(position), color(color), borderThickness(borderThickness) {}

    virtual void draw()
    {
        cout << "Shape Drawn" << endl;
    }

    virtual void calculateArea()
    {
        cout << "Area Calculated" << endl;
    }

    virtual void caluclatePerimeter()
    {
        cout << "Perimeter Calculated" << endl;
    }
};

class Circle : public Shape
{
private:
    float radius;
    Coordinates center;

public:
    Circle(Coordinates position = {0, 0}, string color = "null", float borderThickness = 0.0, Coordinates center = {0, 0}, float radius = 0) : Shape(position, color, borderThickness), center(center), radius(radius) {}

    void draw() override
    {
        cout << "Circle" << endl;
    }

    void calculateArea() override
    {
        cout << "Area ->" << PI * pow(radius, 2) << endl;
    }

    void caluclatePerimeter() override
    {
        cout << "Perimeter ->" << 2 * PI * radius << endl;
    }
};

class Rectangle : public Shape
{
private:
    float width, height;
    Coordinates topLeftCorner;

public:
    Rectangle(Coordinates position = {0, 0}, string color = "null", float borderThickness = 0.0, Coordinates topLeftCorner = {0, 0}, float width = 0, float height = 0) : Shape(position, color, borderThickness), topLeftCorner(topLeftCorner), width(width), height(height) {}

    void draw() override
    {
        cout << "Rectangle" << endl;
    }

    void calculateArea() override
    {
        cout << "Area ->" << width * height << endl;
    }

    void caluclatePerimeter() override
    {
        cout << "Perimeter ->" << (2 * width) + (2 * height) << endl;
    }
};

class Triangle : public Shape
{
private:
    float side1, side2, side3;
    float base = side1, height;

public:
    Triangle(Coordinates position = {0, 0}, string color = "null", float borderThickness = 0.0, float side1 = 0, float side2 = 0, float side3 = 0, float height = 0) : Shape(position, color, borderThickness), side1(side1), side2(side2), side3(side3), height(height) {}

    void draw() override
    {
        cout << "Triangle" << endl;
    }

    void calculateArea() override
    {
        cout << "Area ->" << 0.5 * base * height << endl;
    }

    void caluclatePerimeter() override
    {
        cout << "Perimeter ->" << side1 + side2 + side3 << endl;
    }
};

class Polygon : public Shape
{
private:
    float apothem, length;
    int noOfSides;

public:
    Polygon(Coordinates position = {0, 0}, string color = "null", float borderThickness = 0.0, float apothem = 0, int noOfSides = 0, float length = 0) : Shape(position, color, borderThickness), apothem(apothem), noOfSides(noOfSides), length(length) {}

    void draw() override
    {
        cout << "Polygon" << endl;
    }

    void calculateArea() override
    {
        cout << "Area ->" << 0.5 * apothem * noOfSides * length << endl;
    }

    void caluclatePerimeter() override
    {
        cout << "Perimeter ->" << noOfSides * length << endl;
    }
};

int main()
{
    Coordinates circleCenter = {5, 5};
    Circle circle({0, 0}, "Red", 1.5, circleCenter, 7.0);
    circle.draw();
    circle.calculateArea();
    circle.caluclatePerimeter();
    cout << endl;

    Coordinates rectTopLeft = {10, 10};
    Rectangle rectangle({0, 0}, "Blue", 2.0, rectTopLeft, 6.0, 4.0);
    rectangle.draw();
    rectangle.calculateArea();
    rectangle.caluclatePerimeter();
    cout << endl;

    Triangle triangle({0, 0}, "Green", 1.0, 3.0, 4.0, 5.0, 2.5);
    triangle.draw();
    triangle.calculateArea();
    triangle.caluclatePerimeter();
    cout << endl;

    Polygon polygon({0, 0}, "Yellow", 1.0, 2.0, 6, 3.0);
    polygon.draw();
    polygon.calculateArea();
    polygon.caluclatePerimeter();
    cout << endl;

    return 0;
}
