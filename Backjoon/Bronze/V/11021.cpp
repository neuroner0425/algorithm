#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tc, a, b;
	cin >> tc;
	for(int i = 1; i <= tc; i++){
		cin >> a >> b;
		cout << "Case #" << i << ": " << a + b << "\n";
	}
}