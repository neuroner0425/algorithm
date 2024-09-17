#include <iostream>
#include <vector>
#include <string>

#define MAXN 100000000

using namespace std;

int N, result = MAXN, temp_result;


inline bool isRange(int index){ return (index > 0 && index <= N) ? true : false; }

void click(vector<bool> &arr, int index){
	if(isRange(index - 1)){ arr[index - 1] = !arr[index - 1]; }
	if(isRange(index + 1)){ arr[index + 1] = !arr[index + 1]; }
	arr[index] = !arr[index];
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	vector<bool> target(N + 1, false), now(N + 1, false), mow(N + 1, false);
	
	// MAKE_MAP
	string temp;
	cin >> temp;
	for(int i = 1; i <= N; i++){
		mow[i] = now[i] = (temp[i - 1] == '1');
	}
	cin >> temp;
	for(int i = 1; i <= N; i++){
		target[i] = (temp[i - 1] == '1');
	}
	
	// NONE_CLICK_FIRST
	temp_result = 0;
	for(int i = 2; i <= N; i++){
		if(target[i - 1] != now[i - 1]){
			click(now, i); temp_result++;
		}
	}
	if(target[N] != now[N]) temp_result = MAXN;
	result = (temp_result < result) ? temp_result : result;
	
	// CLICK_FIRST
	temp_result = 0;
	click(mow, 1); temp_result++;
	for(int i = 2; i <= N; i++){
		if(target[i - 1] != mow[i - 1]){
			click(mow, i); temp_result++;
		}
	}
	if(target[N] != mow[N]) temp_result = MAXN;
	result = (temp_result < result) ? temp_result : result;
	
	if(result != MAXN) cout << result << "\n";
	else cout << -1 << "\n";
	return 0;
}