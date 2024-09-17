#include <iostream>

using namespace std;

int arr[100];

int main(){
	int N, M;
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		while(n1 <= n2){
			arr[n1 - 1] = n3;
			n1++;
		}
	}
	for(int i = 0; i < N; i++)
		cout << arr[i] << " ";
	cout << "\n";
}