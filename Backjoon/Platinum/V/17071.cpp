#include <iostream>
#include <queue>
#include <tuple>

#define tii tuple<int, int, int>

using namespace std;

int N, K;
bool visit[2][500001];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	queue<tii> q;
	
	cin >> N >> K;
	
	q.push(make_tuple(0, N, K));
	
	while(!q.empty()){
		tii temp = q.front();
		q.pop();
		int t = get<0>(temp), n = get<1>(temp), k = get<2>(temp);
		if(visit[t % 2][K]){
			cout << t << '\n';
			return 0;
		}
		if(k + t + 1 > 500000) continue;
		if(n < 500000 && !visit[(t + 1) % 2][n + 1]){
			q.push(make_tuple(t + 1, n + 1, k + t + 1));
			visit[(t + 1) % 2][n + 1] = true;
		}
		if(n > 0 && !visit[(t + 1) % 2][n - 1]){
			q.push(make_tuple(t + 1, n - 1, k + t + 1));
			visit[(t + 1) % 2][n - 1] = true;
		}
		if(n * 2 <= 500000 && !visit[(t + 1) % 2][n * 2]){
			q.push(make_tuple(t + 1, n * 2, k + t + 1));
			visit[(t + 1) % 2][n * 2] = true;
		}
	}
	
	cout << "-1\n";
	return 0;
}