#include <iostream>

using namespace std;

int main(){
	int N, temp, min, max;
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> temp;
	max = min = temp;
	while(--N){
		cin >> temp;
		max = (temp > max) ? temp : max;
		min = (min > temp) ? temp : min;
	}
	cout << min << " " << max << "\n";
}