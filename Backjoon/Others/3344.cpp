#include <iostream>
#include <vector>
#include <cmath>
#define pii pair<int, int>

using namespace std;

int N;
long long total;
vector<pii> queens;

bool canQueen(int x, int y){
	for(int i = 0; i < queens.size(); i++){
		pii temp = queens[i];
		if(x == temp.first || y == temp.second || fabs(temp.first - x) == fabs(temp.second - y))
			return false;
	}
	return true;
}

bool bfs(int deep){
	if(deep == N){
		for(int i = 0; i < N; i++){
			pii temp = queens[i];
			cout << temp.second << '\n';
		}
		return true;
	}
	
	for(int i = 0; i < N; i++){
		if(canQueen(i, deep)){
			queens.push_back(make_pair(i, deep));
			if(bfs(deep + 1)) return true;
			queens.pop_back();
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	bfs(0);
}