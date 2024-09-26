#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
 
#define tiiii tuple<int, int, int, int>
#define X first
#define Y second

using namespace std;


int eatTime[101][101];
bool isvisit[101][101][3];
int N, T;
int dx[4] = {-1, 0, 1, 0}, 
	dy[4] = {0, -1, 0, 1};
struct cmp { bool operator()(const tiiii &a, const tiiii &b) { return get<2>(a) > get<2>(b); }};
priority_queue<tiiii, vector<tiiii>, cmp> pq;

inline bool isRange(int x, int y){ return (x > 0 && y > 0 && x <= N && y <= N); }

int main(){

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> T;

	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= N; x++){
			cin >> eatTime[x][y];
		}
	}

	pq.push({1, 1, 0, 0});

	while (!pq.empty()){
		int tx = get<0>(pq.top()), ty = get<1>(pq.top()), tv = get<2>(pq.top()), ti = get<3>(pq.top()) % 3; pq.pop();
		if(isvisit[tx][ty][ti]) continue;
		isvisit[tx][ty][ti] = true;

		if(tx == N && ty == N){
			cout << tv << "\n";
			return 0;
		}

		for (int i = 0; i < 4; i++){
			int nx = tx + dx[i], ny = ty + dy[i];
			if(!isRange(nx, ny) && isvisit[nx][ny]) continue;
			int value = tv + T;
			if (ti == 2){ value += eatTime[nx][ny]; }
			pq.push({nx, ny, value, ti + 1});
		}
	}
}