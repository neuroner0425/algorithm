#include <iostream>

using namespace std;

int N;
bool arr[100][100];

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
				if(arr[i][k] && arr[k][j]) arr[i][j] = true;
			}
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}