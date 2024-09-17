#include <iostream>
#include <string>

using namespace std;

int main(){
	int N;
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	while(N--){
		int R; string str;
		cin >> R >>  str;
		for(int i = 0; i < str.size(); i++){
			for(int r = 0; r < R; r++){
				cout << str[i];
			}
		}
		cout << "\n";
	}
}