#include <iostream>
using namespace std;

class PublicExample {
public:
    int publicVar;  // Public member

    void displayPublicVar() {
        cout << "Public variable: " << publicVar << endl;
    }
};

int main() {
    PublicExample obj;
    obj.publicVar = 15;  // Directly accessing public member
    obj.displayPublicVar();  // Output: Public variable: 15

    return 0;
}
