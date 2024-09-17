#include <iostream>

using namespace std;

int main(){
	int num1, num2;
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(1){
		cin >> num1 >> num2;
		if(!num1 && !num2) break;
		cout << num1 + num2 << "\n";
	}
}