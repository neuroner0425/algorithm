#include <iostream>

using namespace std;

int M,N;
int bee[1110][1110],seed[2220];

int main(){
	cin >> M >> N;
	for (int i=0;i<N;i++){
		int x,y,z; cin >> x >> y >> z;
		y += x;
		seed[x]++; seed[y]++;
	}
	int cnt = 0, pos = 0;
	for (int i=M-1;i>=0;i--){
		cnt += seed[pos++];
		bee[i][0] = cnt;
	}
	for (int j=1;j<M;j++){
		cnt += seed[pos++];
		bee[0][j] = cnt;
	}
	for (int i=1;i<M;i++) {
		for (int j=1;j<M;j++){
			// bee[i][j] = bee[0][j];
		}
	}
	
	
	for (int i=0;i<M;i++){
		for (int j=0;j<M;j++){
			if (j) cout << " ";
			cout << bee[i][j];
		}
		cout << "\n";
	}
	return 0;
}