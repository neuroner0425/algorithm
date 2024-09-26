#include <bits/stdc++.h>

using namespace std;

int n,t;
int counts[10001] = {0, };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cin >> n;
    
    for(int i=0; i < n; i++) {
        std::cin >> t;
        counts[t]++;
    }
    
    for(int i=0; i < 10001; i++) {
        for(int k=0; k < counts[i]; k++) {
            std::cout << i << '\n';
        }
    }
}