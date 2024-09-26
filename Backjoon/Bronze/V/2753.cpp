#include <bits/stdc++.h>
using namespace std;

int y;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> y;

    if ((!(y % 400) || (!(y % 4) && (y % 100))))
    {
        cout << 1;
    }else{
        cout << 0;
    }
}