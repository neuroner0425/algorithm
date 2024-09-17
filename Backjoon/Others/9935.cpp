#include <iostream>
#include <string>

using namespace std;

int main(){
	int ss, bs, sa = 0;
	string str, bomb, ans = "";
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> str >> bomb;
	ss = str.size(); bs = bomb.size();
	
	for(int i = 0; i < ss; i++){
		ans += str[i]; sa++;
		if(ans.back() == bomb.back()){
			int lastIndex = ans.size() - 1;
			bool isNot = false;
			for(int j = 1; j < bs; j++){
				if(ans[lastIndex - j] != bomb[bs - 1 - j]){ isNot = true; break; }
			}
			if(isNot) continue;
			for(int j = 0; j < bs; j++){
				ans.pop_back();
			}
		}
	}
	if(ans.size()){
		cout << ans << "\n";
	}else{
		cout << "FRULA\n";
	}
}