#include <iostream>
#include <string>

using namespace std;

bool sector[3][3][10];
bool vert[10][10]; // x, v
bool hori[10][10]; // y, v 
int map[10][10];
int cnt=0;

bool dfs(int index){
    if (cnt++ >= 10000000) return true;
	if(index >= 82) return true;
	
	int x = (index - 1) % 9 + 1;
	int y = (index - 1) / 9 + 1;
	if(map[x][y]) return dfs(index + 1);
	for(int v = 1; v <= 9; v++){
		if(!vert[x][v] && !hori[y][v] && !sector[(x-1)/3][(y-1)/3][v]){
			map[x][y] = v;
			vert[x][v] = hori[y][v] = sector[(x-1)/3][(y-1)/3][v] = true;
			if(dfs(index + 1)) return true;
			map[x][y] = 0;
			vert[x][v] = hori[y][v] = sector[(x-1)/3][(y-1)/3][v] = false;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	for(int j = 1; j <= 9; j++){
		string temp; cin >> temp;
		for(int i = 1; i <= 9; i++){
			map[i][j] = temp[i - 1] - '0';
			if(map[i][j]){
				hori[j][map[i][j]] = true;
				vert[i][map[i][j]] = true;
				sector[(i-1)/3][(j-1)/3][map[i][j]] = true;
			}
		}
	}
	
	if(dfs(1)){
		for(int j = 1; j <= 9; j++){
			for(int i = 1; i <= 9; i++){
				cout << map[i][j];
			}
			cout << "\n";
		}
		return 0;
	}
	cout << "WTF";
	return 0;
}