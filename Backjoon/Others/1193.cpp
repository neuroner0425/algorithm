#include <iostream>

using namespace std;

int main(){
	int i = 1, N;
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	while(N - i > 0){
		N -= i; i++;
	}
	if(i % 2){
		int x = i, y = 1;
		for(int i = 1; i < N; i++){
			x--; y++;
		}
		cout << x << "/" << y << "\n";
	}else{
		int x = 1, y = i;
		for(int i = 1; i < N; i++){
			x++; y--;
		}
		cout << x << "/" << y << "\n";
	}
}