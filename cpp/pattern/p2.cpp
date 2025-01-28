#include <bits/stdc++.h>
using namespace std;

void pattern3(int N)
{
    for (int i = 5; i >=0; i--)
    {
        for (int j = 1; j <=i; j++)
        {
            cout <<i<<" ";
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