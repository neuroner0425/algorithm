#include <iostream>
#include <string>

using namespace std;

int main(){
	int n, result = 0;
	string str;
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> str;
	for(int i = 0; i < n; i++){
		result += str[i] - '0';
	}
	cout << result << "\n";
}