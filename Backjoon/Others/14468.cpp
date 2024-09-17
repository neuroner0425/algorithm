#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool cross[26][26], isOpen[26];
vector<char> vt;

void reaseChar(char c){
	for(int i = vt.size() - 1; i >= 0; i--){
		if(vt[i] == c){
			vt.erase(vt.begin() + i);
			return;
		}else{
			cross[c - 'A'][vt[i] - 'A'] = true;
			cross[vt[i] - 'A'][c - 'A'] = true;
		}
	}
}

int main(){
	int result = 0;
	string str;
	
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> str;
	
	for(int i = 0; i < 52; i++){
		char c = str[i];
		if(isOpen[c - 'A']){
			isOpen[c - 'A'] = false;
			reaseChar(c);
		}else{
			isOpen[c - 'A'] = true;
			vt.push_back(c);
		}
	}
	
	for(int i = 0; i < 26; i++){
		for(int j = i + 1; j < 26; j++){
			if(cross[i][j]) result++;
		}
	}
	cout << result << "\n";
}