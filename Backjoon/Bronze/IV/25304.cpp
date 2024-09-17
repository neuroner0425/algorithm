#include <iostream>

using namespace std;

int main(){
	int total, t, pr, n;
	cin >> total >> t;
	for(int i = 0; i < t; i++){
		cin >> pr >> n;
		total -= pr * n;
	}
	if(total) cout << "No\n";
	else cout << "Yes\n";
}