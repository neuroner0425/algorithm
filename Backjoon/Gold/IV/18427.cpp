#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

const int MOD = 10007;

vector<int> split(string &str, char Delimiter) {
    istringstream iss(str);
    string buffer;
    vector<int> result;
    while (getline(iss, buffer, Delimiter)) { result.push_back(stoi(buffer)); }
    return result;
}

int main() {
    int N, M, H;
    scanf("%d %d %d\n", &N, &M, &H);

    vector<vector<int>> blocks(N);
    for (int i = 0; i < N; ++i) {
        string tempString;
        getline(cin, tempString);
        blocks[i] = split(tempString, ' ');
    }

    vector<vector<int>> dp(N + 1, vector<int>(H + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= H; ++j) {
            dp[i][j] = dp[i - 1][j];
            for (int k = 0; k < blocks[i - 1].size(); ++k) {
                if (j >= blocks[i - 1][k]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - blocks[i - 1][k]]) % MOD;
                }
            }
        }
    }

    /*
        i번째 블록까지 고려하여 높이 j를 만드는 방법의 수를 계산합니다.
        dp[i][j] = dp[i - 1][j]는 i번째 블록을 사용하지 않는 경우의 수를 의미합니다.
        for (int k = 0; k < blocks[i - 1].size(); ++k) 루프는 i번째 블록의 각 높이 값을 고려합니다.
        if (j >= blocks[i - 1][k]) 조건은 현재 높이 j가 블록의 높이 값보다 크거나 같은 경우를 체크합니다.
        dp[i][j] = (dp[i][j] + dp[i - 1][j - blocks[i - 1][k]]) % MOD는 i번째 블록을 사용하여 높이 j를 만드는 경우의 수를 추가합니다.
    */

    cout << dp[N][H] << "\n";
    return 0;
}

