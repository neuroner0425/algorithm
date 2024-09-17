#include <iostream>

using namespace std;

int main(){
	int N, result;
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	if(N % 2){
		result = ((N + 1) / 2) * N;
	}else{
		result = (N / 2) * (N - 1) + N;
	}
	cout << result << "\n";
}