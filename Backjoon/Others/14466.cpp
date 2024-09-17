#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define X first
#define Y second

using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int N, K, R, remainingCows, result;
bool cantGo[101][101][4], isVisit[101][101], isCow[101][101];
pii cows[100];

void swapii(int &a, int &b){ int temp = a; a = b; b = temp; }
bool isRange(const int &x, const int &y){ return (x > 0 && x <= N && y > 0 && y <= N); }
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K >> R; remainingCows = K;
	while(R--){
		int r1, r2, c1, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		if(r1 != r2){
			if(r1 > r2) swapii(r1, r2);
			cantGo[r1][c1][2] = true; cantGo[r2][c2][0] = true;
		}else{
			if(c1 > c2) swapii(c1, c2);
			cantGo[r1][c1][3] = true; cantGo[r2][c2][1] = true;
		}
	}
	for(int cn = 0; cn < K; cn++){
		int x, y;
		cin >> x >> y;
		cows[cn] = {x,y};
		isCow[x][y] = true;
	}
	
	for(int cn = 0; cn < K; cn++){
		pii cc = cows[cn];
		if(isVisit[cc.X][cc.Y]) continue;
		int findCows = 1;
		queue<pii> q; q.push(cc); isVisit[cc.X][cc.Y] = true;
		while(!q.empty()){
			int tx = q.front().X, ty = q.front().Y; q.pop();
			for(int i = 0; i < 4; i++){
				int nx = tx + dx[i], ny = ty + dy[i];
				if(isVisit[nx][ny] || !isRange(nx, ny)) continue;
				if(cantGo[tx][ty][i]) continue;
				isVisit[nx][ny] = true;
				if(isCow[nx][ny]) findCows++;
				q.push({nx,ny});
			}
		}
		remainingCows -= findCows;
		result += findCows * remainingCows;
	}
	cout << result << "\n";
}