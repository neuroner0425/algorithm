#include <bits/stdc++.h>

#define loop(i, s, n) for (int i = s; i < n; i++)
using namespace std;

int cheas[6];
int basic[6] = {1, 1, 2, 2, 2, 8};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    loop(i, 0, 6)
    {
        cin >> cheas[i];
    }
    cout << basic[0] - cheas[0];
    loop(i, 1, 6)
    {
        cout << " " << basic[i] - cheas[i];
    }
}
