#include <bits/stdc++.h>
using namespace std;
#define loop(i, s, n) for (int i = s; i < n; i++)

string str;

char changeChar(char c) { return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c + 'A' - 'a'; }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    loop(i,0,str.length()){
        str[i] = changeChar(str[i]);
    }
    cout << str;
}