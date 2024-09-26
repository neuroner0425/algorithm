#include <bits/stdc++.h>
#define loop(i, s, n) for (int i = s; i < n; i++)
using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    loop(i, 1, 10)
    {
        cout << n << " * " << i << " = " << n*i << '\n';
    }
}