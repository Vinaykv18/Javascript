// C++ program to demonstrate static
// variables inside a class

// #include <iostream>
// using namespace std;

// class GfG {
// public:
// 	static int i;

// 	GfG(){
// 		// Do nothing
// 	};
// };

// int main()
// {
// 	GfG obj1;
// 	GfG obj2;
// 	obj1.i = 2;
// 	obj2.i = 3;

// 	// prints value of i
// 	cout << obj1.i << " " << obj2.i;
// }
// undefined reference to `GfG::i'
// collect2: error: ld returned 1 exit status
//-------------------------------------------------------------
// C++ program to demonstrate static
// variables inside a class

#include <iostream>
using namespace std;

class GfG {
public:
	static int i;
	GfG(){
		i = 10;
		i++;
	};
};
int GfG::i = 1;
int main()
{
	GfG obj;
	cout << obj.i;

}
