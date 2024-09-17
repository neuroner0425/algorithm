#include <iostream>

using namespace std;

int main(){
	int H, M;
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> H >> M;
	H += 23;
	M += 15;
	if(M / 60){
		M %= 60;
		H += 1;
	}
	H %= 24;
	cout << H << " " << M << "\n";
}