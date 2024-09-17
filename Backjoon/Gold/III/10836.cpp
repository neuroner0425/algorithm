#include <iostream>
#include <vector>

using namespace std;

int M, N, nowGrow[701][701], guideMap[1400];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> M >> N;
	
	int bigger = 0;
	
	while(N--){
		int num0, num1, num2;
		cin >> num0 >> num1 >> num2;
		guideMap[num0]++;
		guideMap[num0 + num1]++;
	}
	
	for (int i = M - 1; i >= 0; i--){
		bigger += guideMap[M - 1 - i];
		nowGrow[0][i] = bigger;
	}
	for (int i = 1; i < M; i++){
		bigger += guideMap[M - 1 + i];
		nowGrow[i][0] = bigger;
	}
	
	for(int j = 1; j < M; j++){
		for(int i = 1; i < M; i++){
			nowGrow[i][j] = nowGrow[i][0];
		}
	}
	
	for(int i = 0; i < M; i++){
		cout << nowGrow[0][i] + 1;
		for(int j = 1; j < M; j++){
			cout << " " << nowGrow[j][i] + 1;
		}
		cout << "\n";
	}
}