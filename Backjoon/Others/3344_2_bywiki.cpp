#include <iostream>
#include <vector>
#define pii pair<int, int>

using namespace std;

int N;
// vector<pii> queens;

// bool check(){
// 	for(int i = 0; i < N; i++){
// 		for(int j = 0; j < N && i != j; j++){
// 			pii temp = queens[i], temp2 = queens[j];
// 			if(temp2.first == temp.first || temp2.second == temp.second || fabs(temp.first - temp2.first) == fabs(temp.second - temp2.second))
// 				return 1;
// 		}
// 	}
// 	return 0;
// }

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	// int k = 1;
	
	if(N % 6 == 2){
		for(int i = 2; i <= N; i += 2){
			cout << i << '\n';
			// queens.push_back(make_pair(++k, i));
		}
		cout << 3 << '\n' << 1 << '\n';
		// queens.push_back(make_pair(++k, 3));
		// queens.push_back(make_pair(++k, 1));
		for(int i = 7; i <= N; i += 2){
			cout << i << '\n';
			// queens.push_back(make_pair(++k, i));
		}
		cout << 5 << '\n';
		// queens.push_back(make_pair(++k, 5));
	}else if(N % 6 == 3){
		for(int i = 4; i <= N; i += 2){
			cout << i << '\n';
			// queens.push_back(make_pair(++k, i));
		}
		cout << 2 << '\n';
		// queens.push_back(make_pair(++k, 2));
		for(int i = 5; i <= N; i += 2){
			cout << i << '\n';
			// queens.push_back(make_pair(++k, i));
		}
		cout << 1 << '\n' << 3 << '\n';
		// queens.push_back(make_pair(++k, 1));
		// queens.push_back(make_pair(++k, 3));
	}else{
		for(int i = 2; i <= N; i += 2) {
			cout << i << '\n';
			// queens.push_back(make_pair(++k, i));
		}
		for(int i = 1; i <= N; i += 2) {
			cout << i << '\n';
			// queens.push_back(make_pair(++k, i));
		}
	}
	// cout << "result : " << (check() ? "NO" : "YES");
}