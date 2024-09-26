#include <bits/stdc++.h>

using namespace std;

int fibo[46] = {0,1};

int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= 45; i++)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    cout << fibo[n];
}