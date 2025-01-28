#include <iostream>
using namespace std;

class PrivateExample {
private:
    int privateVar;

public:
    void setPrivateVar(int value) {
        privateVar = value;  // Can access private member inside the class
    }

    void displayPrivateVar() {
        cout << "Private variable: " << privateVar << endl;
    }
};

int main() {
    PrivateExample obj;
    obj.setPrivateVar(10);
    obj.displayPrivateVar();  // Output: Private variable: 10

    // obj.privateVar = 5;  // Error: Cannot access private member directly
    return 0;
}
