#include <iostream>
#include <string>

using namespace std;

int main(){
	int N;
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	while(N--){
		string temp;
		cin >> temp;
		cout << temp[0] << temp[temp.size() - 1] << "\n";
	}
}