#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define ll long long

using namespace std;

int bs_n(vector<int> &arr, int start, int last, int num) {
	int lower = (lower_bound(arr.begin() + start, arr.end() - last, num) - (arr.begin() + start));
	int upper = (upper_bound(arr.begin() + start, arr.end() - last, num) - (arr.begin() + start));
	return upper - lower;
}

int main(){
	int N, temp;
	ll sum = 0, res = 0;
	
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	vector<int> arr(N + 1);
	
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
		sum += arr[i];
	}
	
	sort(arr.begin() + 1, arr.end());
	
	// 마지막과 마지막에서 한칸 전이 제거되는 경우
	if(sum - arr[N] - arr[N-1] == arr[N-2] * 2) res++;
	
	// 마지막만 고정으로 제거되는 경우
	temp = bs_n(arr, 1, 2, sum - arr[N] - arr[N - 1] * 2);
	if(temp > 0) res += temp;
	
	// 마지막칸에 제거되지 않는 경우
	for(int i = 1; i < N - 1; i++){
		temp = bs_n(arr, i + 1, 1, sum - arr[i] - arr[N] * 2);
		if(temp > 0) res += temp;
	}
	
	cout << res << "\n";
    return 0;
}