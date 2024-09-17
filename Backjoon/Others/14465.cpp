#include <iostream>
#define MAX 100001

using namespace std;

int N, K, B, temp, result = MAX;
bool isBreak[MAX];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K >> B;
	while(B--){
		int indexB; cin >> indexB;
		isBreak[indexB] = true;
	}
	for(int i = 0; i < K; i++)
		temp += isBreak[i];
	
	for(int i = 1; i <= N - K + 1; i++){
		temp -= isBreak[i - 1];
		temp += isBreak[i + K - 1];
		result = (temp < result) ? temp : result;
	}
	cout << result << "\n";
}