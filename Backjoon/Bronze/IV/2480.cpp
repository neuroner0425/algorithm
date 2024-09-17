#include <iostream>

using namespace std;

int main(){
	int N1, N2, N3;
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N1 >> N2 >> N3;
	if(N1 == N2 && N2 == N3 && N1 == N3){
		cout << 10000 + N1 * 1000 << "\n";
	}else if(N1 == N2){
		cout << 1000 + N1 * 100 << "\n";
	}else if(N2 == N3){
		cout << 1000 + N3 * 100 << "\n";
	}else if(N1 == N3){
		cout << 1000 + N1 * 100 << "\n";
	}else{
		int max = (N1 > N2) ? N1 : N2;
		max = (N3 > max) ? N3 : max;
		cout << max * 100 << "\n";
	}
}