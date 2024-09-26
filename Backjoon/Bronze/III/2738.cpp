#include <bits/stdc++.h>
#define loop(i, s, n) for (int i = s; i < n; i++)
using namespace std;

int n, m, arryA[100][100], arryB[100][100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    loop(i, 0, n)
    {
        loop(j, 0, m)
        {
            cin >> arryA[j][i];
        }
    }
    loop(i, 0, n)
    {
        loop(j, 0, m)
        {
            cin >> arryB[j][i];
        }
    }

    loop(i, 0, n)
    {
        cout << arryA[0][i] + arryB[0][i];
        loop(j, 1, m)
        {
            cout << " " << arryA[j][i] + arryB[j][i];
        }
        cout << '\n';
    }
}