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

    // Function to modify brand
    void setBrand(string b) {
        brand = b;
    }

    // Function to modify year
    void setYear(int y) {
        year = y;
    }

    void display() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    Car car1("Tesla", 2022); // Parameterized constructor is called
    car1.display(); // Output: Brand: Tesla, Year: 2022

    // Modify values using setter functions
    car1.setBrand("BMW");
    car1.setYear(2023);
    car1.display(); // Output: Brand: BMW, Year: 2023

    return 0;
}

