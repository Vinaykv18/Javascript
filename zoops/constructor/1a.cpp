#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    int year;

    // Default constructor
    Car() {
        brand = "vinay";
        year = 25;
    }

    void display() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    Car car1; // Default constructor is called
    car1.display(); // Output: Brand: Unknown, Year: 0
    return 0;
}
