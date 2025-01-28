#include <bits/stdc++.h>
using namespace std;
class Base_class{
  public :
      virtual void show(){
          cout << "Apni Kaksha base" << endl;
}
};
class Derived_class : public Base_class{
  public :
      void show(){
          cout << "Apni Kaksha derived" << endl;
}
};
int main()
{
  Base_class *b;
  Derived_class d;
  b = &d;
  b->show();
  d.show(); // prints the content of show() declaredin derived
  return 0;
}