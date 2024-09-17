#include <iostream>
#include <vector>
#include <stack>
#define pii pair<int, int>
#define mp(i,j) make_pair(i,j)
#define ts tttemp.second

using namespace std;

void tc(int n){
	int cost = 0, temp;
	vector<vector<int> > mapnext(n + 1,vector<int>());
	vector<bool> mapvisit(n+1, 0);
	vector<char> maptype(n+1);
	vector<int> mapcost(n+1);
	stack<pii> st;
	
	for(int i = 1; i <= n; i++){
		cin >> maptype[i] >> mapcost[i] >> temp;
		while(temp){
			mapnext[i].push_back(temp);
			cin >> temp;
		}
	}
	
	//BFS
	st.push(mp(0, 1));
	int tap = 0;
	while(!st.empty()){
		pii tttemp = st.top();
		st.pop();
		if(tttemp.first == 0){
			// /*LOG*/ for(int k = 0; k < tap; k++){ cout << "	"; } cout << ts << " " << cost << "";
			if(maptype[ts] == 'E'){
				if(ts == n) { cout << "Yes\n"; return; }
				mapvisit[ts] = true;
				// /*LOG*/ cout << "(Y)";
				tap++;
				st.push(mp(1, ts));
				for(int i = 0; i < mapnext[ts].size(); i++){
					// /*LOG*/ cout << "PS";
					if(mapvisit[mapnext[ts][i]]) continue;
					st.push(mp(0, mapnext[ts][i]));
				}
			}
			else if(maptype[ts] == 'L'){
				if(ts == n) { cout << "Yes\n"; return; }
				mapvisit[ts] = true;
				// /*LOG*/ cout << "(Y)";
				tap++;
				st.push(mp(1, ts));
				if(cost < mapcost[ts]){
					temp = cost - mapcost[ts];
					cost -= temp;
					st.push(mp(-1, temp));
				}
				for(int i = 0; i < mapnext[ts].size(); i++){
					// /*LOG*/ cout << "PS";
					if(mapvisit[mapnext[ts][i]]) continue;
					st.push(mp(0, mapnext[ts][i]));
				}
			}
			else{
				if(cost >= mapcost[ts]){
					if(ts == n) { cout << "Yes\n"; return; }
					mapvisit[ts] = true;
					// /*LOG*/ cout << "(Y)";
					tap++;
					st.push(mp(1, ts));
					cost -= mapcost[ts];
					st.push(mp(-1, mapcost[ts]));
					
					for(int i = 0; i < mapnext[ts].size(); i++){
						// /*LOG*/ cout << "PS";
						if(mapvisit[mapnext[ts][i]]) continue;
						st.push(mp(0, mapnext[ts][i]));
					}
				}
				// /*LOG*/ cout << "	(N)";
			}
			// /*LOG*/ cout << " " << st.size() << "\n";
		}else if(tttemp.first == -1){
			// /*LOG*/ cout << "MC\n";
			cost += ts;
		}else{
			// /*LOG*/ cout << "VF\n";
			mapvisit[ts] = false;
			tap--;
		}
	}
	
	cout << "No\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	while(n){
		tc(n);
		cin >> n;
	}
}