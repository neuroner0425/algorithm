#include <iostream>

using namespace std;

int N, arr[1000], M;
double total;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
		M = (arr[i] > M) ? arr[i] : M;
	}
	for(int i = 0; i < N; i++){
		total += (arr[i] / (double)M) * 100 / N;
	}
	cout << total << '\n';
}