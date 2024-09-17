#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string str;
	int n;
	long long ans = 0;
	cin >> str >> n;
	for(int i = 0; i < str.length(); i++){
		ans *= n;
		if(str[i] >= '0' && str[i] <= '9') ans += str[i] - '0';
		else ans += str[i] - 'A' + 10;
	}
	cout << ans << '\n';
}