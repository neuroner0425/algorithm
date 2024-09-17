#include <iostream>
#include <vector>

using namespace std;

bool dfs(int &n, int target, int &cost, vector<vector<int> > &mapnext, vector<bool> &mapvisit, 
		 vector<char> &maptype, vector<int> &mapcost){
	if(maptype[target] == 'E'){
		if(n == target) return true;
		mapvisit[target] = true;
		for(int i = 0; i < mapnext[target].size(); i++){
			if(mapvisit[mapnext[target][i]]) continue;
			if(dfs(n,mapnext[target][i], cost, mapnext, mapvisit, maptype, mapcost)) return true;
		}
		mapvisit[target] = false;
	}else if(maptype[target] == 'L'){
		if(n == target) return true;
		int tempCost = (cost < mapcost[target]) ? mapcost[target] - cost : 0;
		mapvisit[target] = true; cost += tempCost;
		for(int i = 0; i < mapnext[target].size(); i++){
			if(mapvisit[mapnext[target][i]]) continue;
			if(dfs(n,mapnext[target][i], cost, mapnext, mapvisit, maptype, mapcost)) return true;
		}
		mapvisit[target] = false; cost -= tempCost;
	}else{
		if(cost >= mapcost[target]){
			if(n == target) return true;
			int tempCost = mapcost[target];
			mapvisit[target] = true; cost -= tempCost;
			for(int i = 0; i < mapnext[target].size(); i++){
				if(mapvisit[mapnext[target][i]]) continue;
				if(dfs(n,mapnext[target][i], cost, mapnext, mapvisit, maptype, mapcost)) return true;
			}
			mapvisit[target] = false; cost += tempCost;
		}
	}
	return false;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	while(n){
		int cost = 0, temp;
		vector<vector<int> > mapnext(n + 1,vector<int>());
		vector<bool> mapvisit(n+1, 0);
		vector<char> maptype(n+1);
		vector<int> mapcost(n+1);

		for(int i = 1; i <= n; i++){
			cin >> maptype[i] >> mapcost[i] >> temp;
			while(temp){ mapnext[i].push_back(temp); cin >> temp; }
		}

		if(dfs(n, 1, cost, mapnext, mapvisit, maptype, mapcost)) cout << "Yes\n";
		else cout << "No\n";
		
		cin >> n;
	}
}