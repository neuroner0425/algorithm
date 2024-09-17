#include <iostream>

using namespace std;

int N, arr[2002], dp[1001][1001];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
	}
	for(int i = 1; i <= N; i++){
		cin >> arr[N + i];
	}
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if((arr[i] > arr[N + j] ? arr[i] - arr[N + j] : arr[N + j] - arr[i]) <= 4){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}else{
				dp[i][j] = (dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]);
			}
		}
	}
	cout << dp[N][N] << "\n";
}