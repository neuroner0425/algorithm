#include <iostream>

using namespace std;

bool isAnswel;
int exAnswel;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, a, b, arr[50];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	if(n == 1){ cout << "A\n"; return 0; }
	if(n == 2){
		for(a = -200; a <= 200; a++){
			b = arr[1] - arr[0] * a;
			if((arr[1] * a + b) >= -100 && (arr[1] * a + b) <= 100){
				if(isAnswel && (exAnswel != arr[n - 1] * a + b)){ cout << "A\n"; return 0; }
				exAnswel = arr[n - 1] * a + b; isAnswel = true;
			}
		}
		if(isAnswel) cout << exAnswel << "\n";
		else cout << "B\n";
	}else{
		for(a = -200; a <= 200; a++){
			bool no = false;
			b = arr[1] - arr[0] * a;
			for(int i = 2; i < n; i++){
				if(arr[i] != arr[i-1] * a + b){
					no = true;
					break;
				};
			}
			if(!no){
				if(isAnswel && (exAnswel != arr[n - 1] * a + b)){ cout << "A\n"; return 0; }
				exAnswel = arr[n - 1] * a + b; isAnswel = true;
			}
		}
		if(isAnswel) cout << exAnswel << "\n";
		else cout << "B\n";
	}
}