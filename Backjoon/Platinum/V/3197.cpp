#include <iostream>
#include <queue>
#include <vector>
#include <string>

#define pii pair<int,int>
#define X first
#define Y second

using namespace std;

int R, C, ti, tx, ty, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
pii txy;
int days[1501][1501], dayTemp;
char MAP[1501][1501];
bool isVisit[1501][1501];

queue<pii> q;
vector<pii> swans;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> R >> C;
	for(int i = 1; i <= R; i++){
		string temp;
		cin >> temp;
		for(int j = 1; j <= C; j++){
			MAP[j][i] = temp[j-1];
			if(temp[j-1] == 'L'){
				swans.push_back(make_pair(j,i));
				MAP[j][i] = 'S';
			}else if(temp[j-1] == '.'){
				q.push(make_pair(j,i));
			}
		}
	}
	
	MAP[swans[0].X][swans[0].Y] = 'E';
	ti = makeSwan(swans[0], 0);
	if(ti + 1){ cout << 0 << " end at first \n"; return 0; }
	makeSwan(swans[1], 0);
	q.push(make_pair(0,0));
	
	while(!q.empty()){
		txy = q.front(); q.pop();
		if(){ continue; }
		if(MAP[txy.X][txy.Y] == '.'){ makeWt(txy); continue; }
		if(txy.X == 0){ printMap(++dayTemp); q.push(make_pair(0,0)); continue; }
		
		
		int day = days[txy.X][txy.Y];
		char tc = MAP[txy.X][txy.Y];
		
		
		for(int i = 0; i < 4; i++){
			tx = txy.X + dx[i]; ty = txy.Y + dy[i];
			     if(tx < 1 || ty < 1 || tx > C || ty > R ){ continue; }
			else if(MAP[tx][ty] == '.') {
				days[tx][ty] = day;
				ti = makeWt(make_pair(tx, ty));
				if(ti + 1){ cout << (ti + 1) / 2 << " end at second\n"; return 0; }
			}
			else if(MAP[tx][ty] == 'X') {
				days[tx][ty] = day + 1;
				q.push(make_pair(tx, ty));
			}
			else if(MAP[tx][ty] == 'L'){
				cout << (day + 1) / 2 << " end at third\n";
				return 0;
			}
		}
	}
}