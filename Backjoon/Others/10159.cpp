#include <iostream>
#include <set>

using namespace std;

int main(){
	int N, M;
	set<int> higher[101], lower[101];
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	while(M--){
		int H, L;
		cin >> H >> L;
		lower[H].insert(L);
		higher[L].insert(H);
		for(set<int>::iterator i = lower[L].begin(); i != lower[L].end(); i++){
			lower[H].insert(*i);
			higher[*i].insert(H);
		}
		for(set<int>::iterator i = higher[H].begin(); i != higher[H].end(); i++){
			higher[L].insert(*i);
			lower[*i].insert(L);
			for(set<int>::iterator it = lower[L].begin(); it != lower[L].end(); it++){
				lower[*i].insert(*it);
				higher[*it].insert(*i);
			}
		}
	}
	
	
	
	
	for(int i = 1; i <= N; i++){
		cout << N - 1 - higher[i].size() - lower[i].size() << "\n";
	}
}