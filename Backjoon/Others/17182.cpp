#include <iostream>
#define INF 999999999

using namespace std;

int N, K;
int iArr[10][10], floyd[10][10], answer = INF;
bool visit[10];

void dfs(int deep, int value, int position){
	// for(int i = 0; i < deep; i++) cout << "  ";
	// cout << deep << " " << value << " " << position << "\n";
	
	if(deep == N - 1){
		if(value < answer)  answer = value;
		return;
	}
	for(int planet = 0; planet < N; planet++){
		if(visit[planet]) continue;
		visit[planet] = true;
		dfs(deep + 1, value + floyd[position][planet], planet);
		visit[planet] = false;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> K;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> iArr[i][j]; floyd[i][j] = iArr[i][j];
		}
	}
	
	for(int k = 0; k < N; k++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(floyd[i][k] + floyd[k][j] < floyd[i][j])
					floyd[i][j] = floyd[i][k] + floyd[k][j];
			}
		}
	}
	
	// cout << "=======LOG=======\n";
	
	// for(int i = 0; i < N; i++){
	// 	for(int j = 0; j < N; j++){
	// 		cout << floyd[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	
	// cout << "=======LOG=======\n";
	
	visit[K] = true;
	dfs(0, 0, K);
	
	// cout << "=======LOG=======\n";
	cout << answer << "\n";
}