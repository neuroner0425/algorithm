#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<int> openSet;
vector<int> vt;
int N, result;

void eraseint(int val){
	for(int i = vt.size() - 1; i >= 0; i--){
		if(vt[i] == val){
			vt.erase(vt.begin() + i);
			return;
		}else{
			result++;
		}
	}
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	N *= 2;
	
	for(int i = 0; i < N; i++){
		int temp; cin >> temp;
		if(openSet.count(temp)){
			openSet.erase(temp);
			eraseint(temp);
		}else{
			openSet.insert(temp);
			vt.push_back(temp);
		}
	}
	cout << result << "\n";
}

// 4640KB 664ms