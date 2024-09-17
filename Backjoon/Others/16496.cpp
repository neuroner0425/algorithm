#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(string &a, string &b){
	return a+b > b+a;
}

int main(){
	vector<string> vt;
	string temp;
	int n;
	
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		vt.push_back(temp);
	}
	sort(vt.begin(), vt.end(), comp);
	temp.clear();
	for(int i = 0; i < n; i++){
		if(stoi(vt[i]) || !temp.empty()){
			temp.append(vt[i]);
		}
	}
	if(temp.empty()){
		cout << 0;
	}else{
		cout << temp;
	}
	cout << '\n';
}