#include <iostream>
#include <algorithm>
using namespace std;
void Printfrequency(string str)
{
  //sort(str.begin(), str.end());
  string res = "";
  char ch = str[0];
  int count = 1;
  for (int i = 1; i < str.length(); i++)
  {
    if (str[i] == ch)
      count++;
    else
    {
      cout << ch << count << " ";
      res += ch;
      res += count+'0';
      count = 1;
      ch = str[i];
    }
  }
  cout << ch << count << " "<<endl;
  res += ch;
  res += count+'0';
  cout<<res;
}

int main()
{
  string str = "takeuforwaaarrrrd";
  Printfrequency(str);
  return 0;
}