#include <iostream>
#include <vector>
#include <algorithm>
#define pii pair<int,int>

using namespace std;

bool cmp(pii &a, pii &b){
	return a.first < b.first;
}

int main(){
	int N;
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	vector<pii> arr(N + 1);
	vector<int> ans(N + 1);
	for(int i = 1; i <= N; i++){
		int temp;
		cin >> temp;
		arr[i] = {temp, i};
	}
	sort(arr.begin() + 1, arr.end(), cmp);
	
	int val = arr[1].first, coo = 0;
	for(int i = 2; i <= N; i++){
		if(val < arr[i].first){
			coo++; val = arr[i].first;
			ans[arr[i].second] = coo;
		}else{
			ans[arr[i].second] = coo;
		}
	}
	cout << ans[1];
	for(int i = 2; i <= N; i++){
		cout << " " << ans[i];
	}
}