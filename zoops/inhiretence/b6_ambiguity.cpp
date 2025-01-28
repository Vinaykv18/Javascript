// C++ program to resolve inheritance
// ambiguity
//scope resolution operator
// #include <iostream>
// using namespace std;

// class A {
// public:
//     int x;
// };

// class B : virtual public A {
// public:
//     int y;
// };

// class C : virtual public A {
// public:
//     int z;
// };

// class D : public B, public C {
// public:
//     int w;
// };

// int main() {
//     D obj;
//     obj.x = 1; // okay, no ambiguity
//     obj.y = 2; // okay, no ambiguity
//     obj.z = 3; // okay, no ambiguity
//     obj.w = 4; // okay, no ambiguity
//     return 0;
// }

 //----------------------------------------

#include <iostream>
using namespace std;
 class A {
public:
    virtual void show() {
        std::cout << "Class A" << std::endl;
    }
};

class B : public virtual A {
public:
    void show() override {
        std::cout << "Class B" << std::endl;
    }
};

class C : public virtual A {
public:
    void show() override {
        std::cout << "Class C" << std::endl;
    }
};

class D : public B, public C {
public:
    void show() override {
        std::cout << "Class D" << std::endl;
    }
};

int main() {
    D obj;
    //obj.show();  // Outputs: Class D
    A* basePtr = &obj;
    basePtr->show();  // Outputs: Class D (resolved correctly via virtual inheritance)
}


//----------------------------------------------------------------------------

// #include <iostream>

// class A {
// public:
//     void show() {
//         std::cout << "Class A" << std::endl;
//     }
// };

// class B : public virtual A {
// public:
//     void show() {
//         std::cout << "Class B" << std::endl;
//     }
// };

// class C : public virtual A {
// public:
//     void show() {
//         std::cout << "Class C" << std::endl;
//     }
// };

// class D : public B, public C {
// public:
//     void show() {
//         std::cout << "Class D" << std::endl;
//     }

//     // Methods to access A's show through B or C
//     void showFromB() {
//         B::A::show();  // Access A's show via B
//     }

//     void showFromC() {
//         C::A::show();  // Access A's show via C
//     }
// };

// int main() {
//     D obj;
//     obj.show();          // Outputs: Class D
//     obj.showFromB();     // Outputs: Class A (via B)
//     obj.showFromC();     // Outputs: Class A (via C)
// }
