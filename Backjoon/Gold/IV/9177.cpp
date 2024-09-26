#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string s1, s2, s3;
int ss1, ss2, ss3;
bool dp[201][201];

bool func(const int &idx1, const int &idx2){
	if(idx1 + idx2 == ss3) return true;
	if(dp[idx1][idx2]) return false;
	dp[idx1][idx2] = true;
	if(idx1 < ss1 && s1[idx1] == s3[idx1 + idx2] && func(idx1 + 1, idx2)) return true;
	if(idx2 < ss2 && s2[idx2] == s3[idx1 + idx2] && func(idx1, idx2 + 1)) return true;
	return false;
}

int main(){
	int n;
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s1 >> s2 >> s3;
		ss1 = s1.size(); ss2 = s2.size(); ss3 = s3.size();
		memset(dp, false, sizeof(dp));
		if(func(0, 0)) cout << "Data set " << i << ": yes\n";
		else cout << "Data set " << i << ": no\n";
	}
}