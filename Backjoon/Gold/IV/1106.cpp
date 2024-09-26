#include <iostream>
#include <vector>

#define pii pair<int, int>

using namespace std;

int main(){
    int C, N, result = 999999999;
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> C >> N;

    vector<pii> cities(N);
    vector<int> dp(C + 101, 999999999);
    dp[0] = 0;

    for(int i = 0; i < N; i++){
        cin >> cities[i].first >> cities[i].second;
    }

    for(int i = 0; i <= C; i++){
        if (dp[i] == 999999999) continue;
        for(int j = 0; j < N; j++){
            if(i + cities[j].second <= C + 100 && dp[i + cities[j].second] > dp[i] + cities[j].first) dp[i + cities[j].second] = dp[i] + cities[j].first;
        }
    }
    for (int i = C; i <= C + 100; i++) {
        if(result > dp[i]) result = dp[i];
    }
    cout << result << "\n";
}