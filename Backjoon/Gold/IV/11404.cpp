#include <iostream>
#include <vector>

#define INF 100000000

using namespace std;

int n, m;
long long arr[101][101];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			arr[i][j] = INF;
		}
	}
	while(m--){
		int i, j, temp;
		cin >> i >> j >> temp;
		if(arr[i][j] > temp) arr[i][j] = temp;
	}
	// cout << "=======LOG=======\n";
	// for(int i = 1; i <= n; i++){
	// 	for(int j = 1; j <= n; j++){
	// 		cout << arr[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(arr[i][k] + arr[k][j] < arr[i][j]){
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
	// cout << "=======LOG=======\n";
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(arr[i][j] >= INF) arr[i][j] = 0;
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}