#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int a,b;
        int res = 1;
        cin >> a >> b;
        for(int j=0; j<b; j++){
            res = (res * a) % 10;
        }
        if(res == 0){
            res = 10;
        }
        cout << res << '\n';
    }
    
}
