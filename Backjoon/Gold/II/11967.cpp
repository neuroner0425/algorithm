#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

#define mp(x,y) make_pair(x,y)
#define pii pair<int, int>
#define X first
#define Y second

using namespace std;

struct PairHash{ template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &v) const{ return std::hash<T1>()(v.first) ^ hash<T2>()(v.second) << 1;}};

unordered_multimap<pii, pii, PairHash> lightMAP;
queue<pii> q;
bool reachable[101][101], light[101][101];
int N, M, result;
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};

void lightOn(int x, int y){
	// cout << "lightOn: " << x << " " << y << " -> ";
	for(auto it = lightMAP.find({x,y}); it != lightMAP.end(); it++) {
		if(x == it->X.X && y == it ->X.Y && !light[it->Y.X][it->Y.Y]){
			light[it->Y.X][it->Y.Y] = true;
			// cout << it->Y.X << "," << it->Y.Y << " | ";
			result++;
			q.push(mp(it->Y.X,it->Y.Y));
		}
	}
	// cout << "\n";
}

void bfs(int x, int y){
	// cout << "BFS: " << x << " " << y << "\n";
	bool isReachable = false;
	vector<vector<bool> > visit(N + 1,vector<bool>(N+1,0));
	queue<pii> tq, ttq;
	
	tq.push(mp(x,y)); visit[x][y] = true;
	ttq.push(mp(x,y));
	while(!tq.empty()){
		pii temp = tq.front(); tq.pop();
		for(int i = 0; i < 4; i++){
			int tx = temp.X + dx[i];
			int ty = temp.Y + dy[i];
			if(tx < 1 || tx > N || ty < 1 || temp.Y > N || !light[tx][ty] || visit[tx][ty]) continue;
			visit[tx][ty] = true;
			if(reachable[tx][ty]){
				isReachable = true;
			}else{
				tq.push(mp(tx,ty));
				ttq.push(mp(tx,ty));
			}
		}
	}
	if(isReachable){
		while(!ttq.empty()){
			pii temp = ttq.front(); ttq.pop();
			lightOn(temp.X, temp.Y);
			reachable[temp.X][temp.Y] = true;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	while(M--){
		int t1, t2, t3, t4;
		cin >> t1 >> t2 >> t3 >> t4;
		lightMAP.insert({{t1, t2}, {t3, t4}});
	}
	result++;
	light[1][1] = reachable[1][1] = true;
	lightOn(1,1);
	while(!q.empty()){
		pii temp = q.front(); q.pop();
		bfs(temp.X, temp.Y);
	}
	cout << result << "\n";
}