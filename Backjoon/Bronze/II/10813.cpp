#include <iostream>

using namespace std;

void swap(int &n1, int &n2){
	int temp = n1;
	n1 = n2;
	n2 = temp;
}

int main(){
	int N, M, arr[100];
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		arr[i] = i+1;
	for(int i = 0; i < M; i++){
		int n1, n2;
		cin >> n1 >> n2;
		swap(arr[n1 - 1], arr[n2 - 1]);
	}
	for(int i = 0; i < N; i++)
		cout << arr[i] << " ";
	cout << "\n";
}