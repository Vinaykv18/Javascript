#include <iostream>
using namespace std;

class MyClass {
public:
    static int staticVar;  // Static data member

    // Static member function declaration
    static void displayStatic();
};

// Initialize static member outside the class
int MyClass::staticVar = 100;

// Static member function definition
void MyClass::displayStatic() {
    cout << "Static Variable: " << staticVar << endl;
}

int main() {
    // Access static member using the class name and scope resolution operator
   MyClass::staticVar = 200;  // Modify static member
    MyClass::displayStatic();  // Output: Static Variable: 200

    return 0;
}
