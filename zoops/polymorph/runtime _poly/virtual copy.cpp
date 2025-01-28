#include <iostream>
using namespace std;

class Base {
public:
    // virtual function (re-defined in the derived class)
    virtual void print() {
        cout << "print base class" << endl;
    }
    void show() {
        cout << "show base class" << endl;
    }
};

class Derived : public Base {
public:
    void print() override {
        cout << "print derived class" << endl;
    }
    void show() {
        cout << "show derived class" << endl;
    }
};

int main() {
    Base* bptr;
    Derived d;
    bptr = &d;
    // virtual function, binded at runtime
    bptr->print();
    // Non-virtual function, binded at compile time
    bptr->show();
    return 0;
}
