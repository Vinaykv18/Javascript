// C++ program to demonstrate static
// member function in a class
#include <iostream>
using namespace std;
class GfG {
public:
	static void printMsg() {
		 cout << "Welcome to GfG!"; 
		 }
};
int main()
{
	GfG::printMsg();
}
