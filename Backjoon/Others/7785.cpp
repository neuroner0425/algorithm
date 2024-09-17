#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool cmp(string &s1, string &s2){
	return s1 > s2;
}

int main ()
{
	int n;
	vector<string> vt;
	unordered_set<string> hset;
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	while(n--){
		string name, method;
		cin >> name >> method;
		if(method == "enter"){
			hset.insert(name);
		}else{
			hset.erase(name);
		}
	}
	
	for(auto it = hset.begin(); it != hset.end(); it++){
		vt.push_back(*it);
	}
	sort(vt.begin(), vt.end(), cmp);
	
	for(int i = 0; i < vt.size(); i++){
		cout << vt[i] << "\n";
	}
	
	return 0;
}