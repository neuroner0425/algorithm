#include <iostream>
#include <queue>

#define pii pair<int, int>

using namespace std;

struct cmp{
	bool operator()(pii &a, pii &b){
		return a.first > b.first;
	}
};

int main(){
	int N, time = 0;
	priority_queue<pii, vector<pii>, cmp> q;
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	while(N--){
		int t1, t2;
		cin >> t1 >> t2;
		q.push(make_pair(t1,t2));
	}
	while(!q.empty()){
		pii temp = q.top(); q.pop();
		if(time < temp.first) time = temp.first;
		time += temp.second;
	}
	cout << time << "\n";
}