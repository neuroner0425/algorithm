#include <iostream>

using namespace std;

int main(){
	int H, M, C;
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> H >> M >> C;
	M += C;
	if(M / 60){
		H += M / 60;
		M %= 60;
	}
	H %= 24;
	cout << H << " " << M << "\n";
}