#include <iostream>
#include <vector>

using namespace std;

int main(){
	int N, ans = 0;
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	vector<bool> isCow(11, false), locCow(11);
	while(N--){
		int cowTemp, locTemp;
		cin >> cowTemp >> locTemp;
		if(isCow[cowTemp]){
			if(locCow[cowTemp] != locTemp) {
				ans++;
				locCow[cowTemp] = locTemp;
			}
		}else{
			isCow[cowTemp] = true;
			locCow[cowTemp] = locTemp;
		}
	}
	cout << ans << "\n";
}