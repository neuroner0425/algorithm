#include <bits/stdc++.h>
using namespace std;
string str;
double res;
int main(void)
{
    cin >> str;
    switch (str[0])
    {
    case 'A':
        res = 4.0;
        break;
    case 'B':
        res = 3.0;
        break;
    case 'C':
        res = 2.0;
        break;
    case 'D':
        res = 1.0;
        break;
    }
    switch (str[1])
    {
    case '+':
        res += 0.3;
        break;
    case '-':
        res -= 0.3;
        break;
    }
    printf("%.1lf",res);
}