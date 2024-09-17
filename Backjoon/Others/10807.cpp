#include <iostream>

using namespace std;

int arr[201];

int main(){
	int N, V;
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	for(int i = 0; i < N; i++){
		int num;
		cin >> num;
		arr[num + 100]++;
	}
	cin >> V;
	cout << arr[V + 100] << "\n";
}