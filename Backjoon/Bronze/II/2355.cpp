#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a, b, res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    if (a < b)
        res = b * (b + 1) / 2 - (a) * (a - 1) / 2;
    else
        res = a * (a + 1) / 2 - (b) * (b - 1) / 2;
    cout << res;
}