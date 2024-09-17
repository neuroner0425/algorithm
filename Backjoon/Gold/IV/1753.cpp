#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int, int>
#define INF 100000000
#define X first
#define Y second

using namespace std;
struct cmp{ bool operator()(pii &a, pii &b) const{ return a.Y > b.Y; } };

int V, E, SP;
vector<int> result(20001, INF);
vector<pii> edges[20001];
priority_queue<pii, vector<pii>, cmp> pq;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> V >> E >> SP;
	while(E--){
		int x, y, value;
		cin >> x >> y >> value;
		edges[x].push_back({y, value});
	}
	
	pq.push({SP, 0});
	
	while(!pq.empty()){
		int tx = pq.top().X, ty = pq.top().Y; pq.pop();
		if(result[tx] < INF){ continue; }
		result[tx] = ty;
		for(int i = 0; i < edges[tx].size(); i++){
			pq.push({edges[tx][i].X, ty + edges[tx][i].Y});
		}
	}
	for(int i = 1; i <= V; i++){
		if(result[i] < INF) cout << result[i] << "\n";
		else cout << "INF\n";
	}
}