#include <iostream>

using namespace std;

int main(){
	int max, temp, index = 1;
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> temp;
	max = temp;
	for(int i = 2; i <= 9; i++){
		cin >> temp;
		if(temp > max){
			max = temp;
			index = i;
		}
	}
	cout << max << "\n" << index << "\n";
}