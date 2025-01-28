#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    int year;

    // Parameterized constructor
    Car(string b, int y) {
        brand = b;
        year = y;
    }

    // Copy constructor
    Car(const Car &obj) {
        brand = obj.brand;
        year = obj.year;
    }

    void display() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    Car car1("Honda", 2021); // Parameterized constructor is called
    Car car2 = car1; // Copy constructor is called

    car2.display(); // Output: Brand: Honda, Year: 2021
    return 0;
}
