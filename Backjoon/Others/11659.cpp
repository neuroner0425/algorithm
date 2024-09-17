#include <iostream>

using namespace std;
int N, M, nums[100001], totals[100001];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		cin >> nums[i];
		totals[i] = totals[i - 1] + nums[i];
	}
	for(int k = 0; k < M; k++){
		int i,j;
		cin >> i >> j;
		cout << totals[j] - totals[i-1] << '\n';
	}
}