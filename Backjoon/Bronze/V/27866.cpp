#include <iostream>
#include <string>

using namespace std;

int main(){
	string str;
	int n;
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> str >> n;
	cout << str[n-1] << "\n";
}