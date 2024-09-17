#include <iostream>

using namespace std;

int N, ans;
int arr[20][20];
bool isnn[20][20];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> arr[i][j];
		}
	}
	for(int k = 0; k < N; k++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(k == i || k == j) continue;
				if(arr[i][j] == arr[i][k] + arr[k][j]) isnn[i][j] = true;
				else if(arr[i][j] > arr[i][k] + arr[k][j]) { cout << "-1\n"; return 0; }
			}
		}
	}
	for(int i = 0; i < N - 1; i++){
		for(int j = i + 1; j < N; j++){
			if(!isnn[i][j]){
				ans += arr[i][j];
			}
		}
	}
	cout << ans << "\n";
}