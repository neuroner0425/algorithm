#include <iostream>

int sn[101], N, L;

using namespace std;

int main(){
	cin >> N >> L;
	
	sn[1] = 1;
	for(int i = 2; i < L; i++)
		sn[i] = sn[i - 1] + i;
	
	for(int i = L; i <= 100; i++){
		sn[i] = sn[i - 1] + i;
		if(!((N - sn[i - 1]) % i) && N - sn[i - 1] >= 0){
			int temp = (N - sn[i - 1]) / i;
			for(int j = 0; j < i; j++)
				cout << temp + j << " ";
			return 0;
		}
	}
	cout << "-1\n";
}