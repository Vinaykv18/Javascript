#include <bits/stdc++.h>
using namespace std;

void pattern3(int n)
{
  for (int i = n-1; i >=0; i--)
  {
    // space
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }
    // satr
    for (int j = 0; j < 2 * i + 1; j++)
    {
      cout << "*";
    }
    // spaaace
    for (int j = 0; j < n - i - 1; j++)
    {
      cout << " ";
    }
    cout << endl;
  }
}

int main()
{
  int N = 5;
  pattern3(N);
  return 0;
}