#include <iostream>

using namespace std;

long long result[10], N, temp;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	
	for(long long i = 1; i <= N; i++){
		temp = i;
		while(temp){
			result[temp % 10]++;
			temp /= 10;
		}
	}
	for(int i = 0; i < 10; i++){
		cout << result[i] << " ";
	}
	cout << '\n';
}