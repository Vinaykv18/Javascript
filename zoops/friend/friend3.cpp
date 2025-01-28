#include <iostream>
using namespace std;

class Rectangle {

    int length;
    int width;

public:
    Rectangle(int l, int w)
    {
        length = l;
        width  = w;
    }

    // Friend function declaration
    friend int getPerimeter(Rectangle& r);  // Friend function can access protected members
};

// Friend function definition
int getPerimeter(Rectangle& r) {
    // Access protected members
    return 2 * (r.length + r.width);
}

int main() {
    Rectangle rect(10, 5);

    // Calculate perimeter using the friend function
    int perimeter = getPerimeter(rect);
    cout << "Perimeter of the rectangle: " << perimeter << endl;  // Output: Perimeter of the rectangle: 30

    return 0;
}
