#include <iostream>

using namespace std;

int main(){
	int N, X, temp;
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> X;
	while(N--){
		cin >> temp;
		if(temp < X) cout << temp << " ";
	}
	cout << "\n";
}