#include <bits/stdc++.h>
using namespace std;

int dp[15][15], temp;

int getDp(int k, int n)
{
    if (!dp[k][n] && 0 < k && 0 < n)
    {
        dp[k][n] = getDp(k, n - 1) + getDp(k - 1, n);
    }
    return dp[k][n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;

    for (int i = 1; i <= 14; i++)
    {
        dp[0][i] = i;
    }
    cin >> tc;
    while (tc--)
    {
        int k, n;
        cin >> k >> n;
        cout << getDp(k, n) << "\n";
    }
    return 0;
}