#include<bits/stdc++.h>
using namespace std;
void Capitalize(string str, int size) {
  for (int i = 0; i < size; i++) {
    if (i == 0 || i == (size - 1) && (int) str[i] >= 97) 
    {
      str[i] = ((char)((int) str[i] - 32));
    } else if (str[i] == ' ')
    {
      if (((int) str[i - 1]) >= 95) 
        str[i - 1] = ((char)((int) str[i - 1] - 32));

      if (((int) str[i + 1]) >= 95)
        str[i + 1] = ((char)((int) str[i + 1] - 32));
    }
  }
  cout<<"String after capitalizing the first and last letter of each word of the string: "<< "\n";
  cout << str << "\n";
}
int main() {
  string str = "take u forward is awesome";
  int size = str.length();

  Capitalize(str, size);
  return 0;
}