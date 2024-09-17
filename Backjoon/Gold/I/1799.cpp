#include <iostream>
#include <vector>
#include <cmath>

#define pii pair<int, int>
#define X first
#define Y second

using namespace std;

int N, res[2], semi_res[2];
bool arr[10][10]; // X, Y
bool diagonal[20][2]; // X - Y + 9, X + Y

bool canDo(pii co, int t){
	if(!arr[co.X][co.Y]) return 0;
	if(diagonal[co.X - co.Y + 9][0]) return 0;
	if(diagonal[co.X + co.Y][1]) return 0;
	return 1;
}

void dfs(int deep){
	
	if(deep >= 2 * N - 1){
		res[deep % 2] = (semi_res[deep % 2] > res[deep % 2]) ? semi_res[deep % 2] : res[deep % 2];
		return;
	}
	if(deep < N){
		for(int i = 0; i < deep + 1; i++){
			if(canDo(make_pair(i, deep - i), deep)){
				diagonal[2 * i - deep + 9][0] = true;
				diagonal[deep][1] = true;
				semi_res[deep % 2]++;
				dfs(deep + 2);
				diagonal[2 * i - deep + 9][0] = false;
				diagonal[deep][1] = false;
				semi_res[deep % 2]--;
			}
		}
		dfs(deep + 2);
	}else{
		for(int i = deep - N + 1; i < N; i++){
			if(canDo(make_pair(i, deep - i), deep)){
				diagonal[2 * i - deep + 9][0] = true;
				diagonal[deep][1] = true;
				semi_res[deep % 2]++;
				dfs(deep + 2);
				diagonal[2 * i - deep + 9][0] = false;
				diagonal[deep][1] = false;
				semi_res[deep % 2]--;
			}
		}
		dfs(deep + 2);
	}
}



int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> arr[j][i];
	dfs(0);
	dfs(1);
	cout << res[0] + res[1] << '\n';
}