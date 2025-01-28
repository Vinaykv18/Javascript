#include <iostream>
using namespace std;

class BaseClass {
protected:
    int protectedVar;  // Protected member

public:
    void setProtectedVar(int value) {
        protectedVar = value;
    }
};

class DerivedClass : public BaseClass {
public:
    void displayProtectedVar() {
        cout << "Protected variable: " << protectedVar << endl;  // Can access protectedVar
    }
};

int main() {
    DerivedClass obj;
    obj.setProtectedVar(20);
    obj.displayProtectedVar();  // Output: Protected variable: 20

    // obj.protectedVar = 30;  // Error: Cannot access protected member directly
    return 0;
}
