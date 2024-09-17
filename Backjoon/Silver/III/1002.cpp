#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pii Jo, Baek;
    int r1, r2;
    long long lenge;

    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> Jo.first >> Jo.second >> r1;
        cin >> Baek.first >> Baek.second >> r2;

        lenge = pow(Jo.first - Baek.first, 2) + pow(Jo.second - Baek.second, 2);
        int cond1 = pow(r1 - r2, 2);
        int cond2 = pow(r1 + r2, 2);
        if (lenge == 0)
        {
            if (cond1 == 0)
                cout << "-1" << '\n';
            else
                cout << "0" << '\n';
        }
        else if (lenge == cond1 || lenge == cond2)
            cout << "1" << '\n';
        else if (cond1 < lenge && lenge < cond2)
            cout << "2" << '\n';
        else
            cout << "0" << '\n';
    }
    return 0;
}