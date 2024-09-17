#include <iostream>
#include <vector>
#include <cmath>
#define pii pair<int, int>

using namespace std;

int N;
vector<pii> queens;

bool check(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N && i != j; j++){
			pii temp = queens[i], temp2 = queens[j];
			if(temp2.first == temp.first || temp2.second == temp.second || fabs(temp.first - temp2.first) == fabs(temp.second - temp2.second))
				return 1;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	int k = 1;
	
	if ((!(N % 2) && N % 6 != 2) || ((N % 2) && (N - 1) % 6 != 2)){
		for(int i = 2; i <= N; i += 2) {
			cout << i << '\n';
			queens.push_back(make_pair(++k, i));
		}
		for(int i = 1; i <= N; i += 2) {
			cout << i << '\n';
			queens.push_back(make_pair(++k, i));
		}
	}else{
		if (N % 2) N--;
		for (int i = 1; i <= N / 2; i++){
			cout << 1 + (2 * i + N / 2 - 3) % N << '\n';
			queens.push_back(make_pair(++k, 1 + (2 * i + N / 2 - 3) % N));
		}
		for (int i = N / 2; i > 0; i--){	
			cout << N - (2 * i + N / 2 - 3) % N << '\n';
			queens.push_back(make_pair(++k, N - (2 * i + N / 2 - 3) % N));
		}
		if (N % 2){
			cout << N + 1 << '\n';
			queens.push_back(make_pair(++k, N + 1));
		}
	}
	cout << "result : " << (check() ? "NO" : "YES");
}