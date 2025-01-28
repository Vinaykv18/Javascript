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

    void display() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    Car car1("vinay",10); // Parameterized constructor is called
    car1.display(); // Output: Brand: Toyota, Year: 2020
    return 10000;
}
