#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define pii pair<int, int>

using namespace std;

int N;
vector<pii> queens;
int inputs[20];

bool compare1(pii a, pii b) {
	return a.second < b.second;
}

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
		sort(queens.begin(), queens.end(), compare1);
		for(int i = 0; i < N; i++){
			cout << queens[i].first + 1 << " ";
		}
		return true;
	}
	
	if(inputs[deep]){
		if(bfs(deep + 1)) return true;
	}else{
		for(int i = 0; i < N; i++){
			if(canQueen(i, deep)){
				queens.push_back(make_pair(i, deep));
				if(bfs(deep + 1)) return true;
				queens.pop_back();
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> inputs[i];
		if(inputs[i]) queens.push_back(make_pair(inputs[i] - 1, i));
	}
	if(bfs(0)) return 0;
	else cout << "-1\n";
}