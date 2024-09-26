#include <bits/stdc++.h>
#define mod 1000000000000000000
#define mo 10

using namespace std;

long long fibo[10001][100];

int main()
{
    int x = 0;
    int n;
    cin >> n;

    fibo[0][0] = 0;
    fibo[1][0] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            fibo[i][j] += fibo[i - 1][j] + fibo[i - 2][j];
            if (fibo[i][j] > mod)
            {
                if (j == x)
                {
                    x++;
                }
                fibo[i][j + 1] += (fibo[i][j] / mod);
                fibo[i][j] %= mod;
            }
        }
    }
    cout << fibo[n][x];
    for (int i = x - 1; i >= 0; i--)
    {
        cout << setfill('0') << setw(18) << fibo[n][i];
    }
}