#include <iostream>
#include <queue>
#include <unordered_map>

#define pii pair<int,int>
#define X first
#define Y second

using namespace std;


int L, N, x, y, head, result, start;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};
unordered_multimap<int, pii> visits[2];
queue<pii> q;
pii nowOper;

bool canGo(){
	if(head % 2){
		for(auto it = visits[0].find(y); it != visits[0].end(); it++) {
			if(x >= it->Y.X && x <= it->Y.Y) return false;
			// cout << "find()" << it->X << "): " << it->Y.X << it->Y.Y << "\n";
		}
	}else{
		for(auto it = visits[1].find(x); it != visits[1].end(); it++) {
			if(y >= it->Y.X && y <= it->Y.Y) return false;
			// cout << "find()" << it->X << "): " << it->Y.X << it->Y.Y << "\n";
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> L >> N;
	for(int i = 0; i < N; i++){
		char tempC;
		cin >> x >> tempC;
		y = (tempC == 'R') ? 1 : -1;
		q.push(make_pair(x,y));
	}
	start = result = head = x = y = 0;
	nowOper = q.front(); q.pop();
	while(1){
		x += dx[head]; y += dy[head];
		result++;
		if(!canGo() || x < -L || y < -L || x > L || y > L){
			break; 
		}
		nowOper.X--;
		if(!nowOper.X){
			if(head % 2){
				// cout << "turn: " << start << " " << y << "\n";
				if(start < y) visits[1].insert({x,{start, y}});
				else visits[1].insert({x,{y, start}});
				start = x;
			}else{
				// cout << "turn: " << start << " " << x << "\n";
				if(start < x) visits[0].insert({y,{start, x}});
				else visits[0].insert({y,{x, start}});
				start = y;
			}
			
			head += nowOper.Y + 4;
			head %= 4;
			if(!q.empty()){
				nowOper = q.front(); q.pop();
			}
		}
	}
	// cout << "\n\nLOG\n";
	// for (auto i : visits[0]) {
	// 	cout << i.X << "(y): " << i.Y.X << " " << i.Y.Y << "\n";
	// }
	// cout << "\n";
	// for (auto i : visits[1]) {
	// 	cout << i.X << "(x): " << i.Y.X << " " << i.Y.Y << "\n";
	// }
	
	cout << result << "\n";
}