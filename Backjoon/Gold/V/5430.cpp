#include <iostream>
#include <string>
#include <deque>

using namespace std;

int tc;

void func(){
	int n, temp = 0;
	string fString, arrString;
	deque<int> dq;
	bool isReverse = false;
	
	cin >> fString >> n >> arrString;
	
	if(n){
		for(int i = 1; i < arrString.length(); i++){
			if(arrString[i] == ',' || arrString[i] == ']'){
				dq.push_back(temp);
				temp = 0;
			}
			else{
				temp *= 10;
				temp += arrString[i] - '0';
			}
		}
	}
	
	for(int i = 0; i < fString.length(); i++){
		if(fString[i] == 'R') isReverse = !isReverse;
		else{
			if(dq.empty()){
				cout << "error\n";
				return;
			}
			if(isReverse){
				dq.pop_back();
			}else{
				dq.pop_front();
			}
		}
	}
	
	if(dq.empty()){
		cout << "[]\n";
		return;
	}
	
	cout << '[';
	if(isReverse){
		for(int i = dq.size() - 1; i > 0; i--){
			cout << dq[i] << ',';
		}
		cout << dq[0] << "]\n";
	}
	else{
		for(int i = 0; i < dq.size() - 1; i++){
			cout << dq[i] << ',';
		}
		cout << dq[dq.size() - 1] << "]\n";
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> tc;
	while(tc--) func();
	return 0;
}