#include <iostream>

using namespace std;

int a, b, c, tc[100], res;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c;
	for(int i = 0; i < 3; i++){
		int in, out;
		cin >> in >> out;
		for(int t = in; t < out; t++)
			tc[t-1]++;
	}
	for(int t = 1; t <= 100; t++){
		if(tc[t-1] == 3){
			res += c * 3;
		}else if(tc[t-1] == 2){
			res += b * 2;
		}else if(tc[t-1] == 1){
			res += a;
		}
	}
	cout << res;
    return 0;

}
