#include <iostream>
using namespace std;

class MyClass {
public:
    int publicVar;  // Public data member

    // Constructor
    MyClass(int x) : publicVar(x) {}

    // Member function declaration
    void display();

private:
    int privateVar;  // Private data member

public:
    // Setter for privateVar
    void setPrivateVar(int value) {
        privateVar = value;
    }

    // Getter for privateVar
    int getPrivateVar() {
        return privateVar;
    }
};

// Member function definition outside the class using scope resolution operator
void MyClass::display() {
    cout << "Public Variable: " << publicVar << endl;
    cout << "Private Variable: " << privateVar << endl;
}

int main() {
    MyClass obj(10);  // Create an object of MyClass
    
    // Access public member directly
    obj.publicVar = 15;  // Modify public member
    cout << "Public Variable (Accessed directly): " << obj.publicVar << endl;

    // Access private member using public setter and getter
    obj.setPrivateVar(20);  // Modify private member using setter
    cout << "Private Variable (Accessed via getter): " << obj.getPrivateVar() << endl;

    // Call member function that accesses both public and private members
    obj.display();

    return 0;
}
