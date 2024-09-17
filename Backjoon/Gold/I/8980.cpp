#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#define tiii tuple<int,int,int>

using namespace std;


bool comp(tiii &a, tiii &b){
	if(get<1>(a) == get<1>(b)){
		return get<0>(a) > get<0>(b);
	}
	return get<1>(a) < get<1>(b);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N, C, M;
	cin >> N >> C >> M;
	long long result = 0;
	vector<int> boxs(N + 1);
	vector<tiii> vt;
	for(int i = 0; i < M; i++){
		int t1,t2,t3;
		cin >> t1 >> t2 >> t3;
		vt.push_back(make_tuple(t1,t2,t3));
	}
	// cout << '\n';
	sort(vt.begin(), vt.end(), comp);
	// for(int i = 0; i < M; i++){
	// 	cout << get<0>(vt[i]) << ' ' << get<1>(vt[i]) << ' ' << get<2>(vt[i]) << '\n';
	// }
	// cout << '\n';
	for(int j = 0; j < M; j++){
		int canbox = C;
		for(int i = get<0>(vt[j]); i < get<1>(vt[j]); i++){
			canbox = (canbox < C - boxs[i]) ? canbox : C - boxs[i];
		}
		if(canbox){
			if(canbox > get<2>(vt[j])){
				canbox = get<2>(vt[j]);
			}
			result += canbox;
			for(int i = get<0>(vt[j]); i < get<1>(vt[j]); i++){
				boxs[i] += canbox;
			}
			// cout << get<0>(vt[j]) << ' ' << get<1>(vt[j]) << ' ' << canbox << '\n';
			// for(int i = 1; i <= N; i++){
			// 	cout << boxs[i] << ' ';
			// }
			// cout << '\n';
		}
	}
	cout << result;
}