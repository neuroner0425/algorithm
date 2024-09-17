#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
int sizeTC, sizeTV;
vector<char> consonants, vowels;
vector<string> stringArr;

void makeVow(const int &deep, const int &index, const int &target, const string &value){
	if(deep == target){ stringArr.push_back(value); return; }
	for(int i = index; i < sizeTV; i++){
		makeVow(deep + 1, i + 1, target, value + vowels[i]);
	}
}

void makeCons(const int &deep, const int &index, const int &target, const string &value){
	if(deep == target){ makeVow(0, 0, L - target, value); return; }
	for(int i = index; i < sizeTC; i++){
		makeCons(deep + 1, i + 1, target, value + consonants[i]);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> L >> C;
	for(int i = 0; i < C; i++){
		char temp;
		cin >> temp;
		if(temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u') consonants.push_back(temp);
		else vowels.push_back(temp);
	}
	sizeTC = consonants.size(); sizeTV = vowels.size();
	
	for(int sizeCons = 1; sizeCons <= sizeTC; sizeCons++){
		if(L - sizeCons < 2 || L - sizeCons > sizeTV) continue;
		makeCons(0, 0, sizeCons, "");
	}
	
	for(int i = 0; i < stringArr.size(); i++){
		sort(stringArr[i].begin(), stringArr[i].end());
	}
	sort(stringArr.begin(), stringArr.end());
	
	// cout << "===LOG===\n";
	
	for(int i = 0; i < stringArr.size(); i++){
		cout << stringArr[i] << "\n";
	}
}

// a t c i s w