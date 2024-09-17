#include <iostream>

using namespace std;

int main(){
	int N;
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N - i; j++){
			cout << " ";
		}
		for(int j = N - i + 1; j <= N; j++){
			cout << "*";
		}
		cout << "\n";
	}
}