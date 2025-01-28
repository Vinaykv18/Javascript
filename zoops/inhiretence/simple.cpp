// C++ program to illustrate how to access the inherited
// members of the base class in derived class
#include <iostream>
using namespace std;

// Base class
class Base {
public:
    // data member
    int publicVar;

    // member method
    void display()
    {
        cout << "Value of publicVar: " << publicVar;
    }
};

// Derived class
class Derived : public Base {
public:
    // Function to display inherited member
    void displayMember()
    {
        // accessing public base class member method
        display();
    }

    // Function to modify inherited member
    void modifyMember(int pub)
    {
        // Directly modifying public member
        publicVar = pub;
    }
};

int main()
{
    // Create an object of Derived class
    Derived obj;

    // Display the initial values of inherited member
    obj.modifyMember(10);

    // Display the modified values of inherited member
    obj.displayMember();

    return 0;
}


// C++ program to show that a derived class
// doesn’t inherit access to private data members.
// However, it does inherit a full parent object.
class A {
public:
    int x;

protected:
    int y;

private:
    int z;
};

class B : public A {
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A {
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};