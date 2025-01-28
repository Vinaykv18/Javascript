#include <bits/stdc++.h>
using namespace std;

void pattern3(int n)
{
    for (int i = 1; i <=2*n-1; i++)
    {
        int stars = i;
        if(i > n) stars = 2*n - i;
        for (int j = 1; j <=stars; j++)
        {
            cout <<"*"<<" ";
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