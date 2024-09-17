#include <iostream>
#include <string>

using namespace std;

bool func(const string &s1, const string &s2, const string &s3){
	int idx1 = 0, idx2 = 0;
	for(int i = 0; i < s3.size(); i++){
		char temp = s3[i];
		if(temp == s1[idx1] && temp == s2[idx2]){
			if(func(s1.substr(idx1 + 1), s2.substr(idx2), s3.substr(i + 1))) idx1++;
			else if(func(s1.substr(idx1), s2.substr(idx2 + 1), s3.substr(i + 1))) idx2++;
			else return false;
		}
		else if(temp == s1[idx1]) idx1++;
		else if(temp == s2[idx2]) idx2++;
		else return false;
	}
	return true;
}

int main(){
	int n;
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		if(func(s1, s2, s3)) cout << "Data set " << i << ": yes\n";
		else cout << "Data set " << i << ": no\n";
	}
}