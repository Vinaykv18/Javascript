#include <iostream>
using namespace std;

// Abstract class with a pure virtual function
class Shape {
public:
    // Pure virtual function
    virtual void draw() = 0;

    // Non-virtual function
    void info()  {
        cout << "This is a shape." << endl;
    }
};

// Derived class 1
class Circle : public Shape {
public:
    // Overriding the pure virtual function
    void draw()  {
        cout << "Drawing a circle." << endl;
    }
};

// Derived class 2
class Rectangle : public Shape {
public:
    // Overriding the pure virtual function
    void draw() {
        cout << "Drawing a rectangle." << endl;
    }
};

int main() {
    // Shape s;  // Error: Cannot instantiate abstract class

    Circle c;
    Rectangle r;
    //c.draw();
    c.draw();
    r.draw();
    // Shape* shapePtr;

    // shapePtr = &c;
    // shapePtr->draw();  // Output: Drawing a circle.

    // shapePtr = &r;
    // shapePtr->draw();  // Output: Drawing a rectangle.

    return 0;
}

