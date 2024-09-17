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
int days[1501][1501];
char MAP[1501][1501];
int isVisit[1501][1501];

queue<pii> q;
vector<pii> swans;

void printMap1(){
	cout << "\nMAP_LOG:\n";
	for(int i = 1; i <= R; i++){
		for(int j = 1; j <= C; j++){
			cout << MAP[j][i];
		}
		cout << "  ";
		for(int j = 1; j <= C; j++){
			cout << days[j][i];
		}
		cout << "  ";
		for(int j = 1; j <= C; j++){
			cout << isVisit[j][i];
		}
		cout << '\n';
	}
}

void printMap(){
	cout << "\nMAP_LOG:\n";
	for(int i = 1; i <= R; i++){
		for(int j = 1; j <= C; j++){
			cout << MAP[j][i];
		}
		cout << '\n';
	}
	cout << '\n';
	for(int i = 1; i <= R; i++){
		for(int j = 1; j <= C; j++){
			cout << days[j][i];
		}
		cout << '\n';
	}
	cout << '\n';
	for(int i = 1; i <= R; i++){
		for(int j = 1; j <= C; j++){
			cout << isVisit[j][i];
		}
		cout << '\n';
	}
}

int makeSwan(pii XY){
	// cout << "LOG SW\n";
	char tc = MAP[XY.X][XY.Y];
	int day = days[XY.X][XY.Y];
	queue<pii> tq;
	tq.push(XY);
	while(!tq.empty()){
		txy = tq.front(); tq.pop();
		for(int i = 0; i < 4; i++){
			tx = txy.X + dx[i]; ty = txy.Y + dy[i];
			     if( (tx < 1 || ty < 1 || tx > C || ty > R)) { continue; }
			else if(MAP[tx][ty] == '.') {
				isVisit[tx][ty] = 2;
				MAP[tx][ty] = tc; 
				days[tx][ty] = day;
				tq.push(make_pair(tx, ty));
			}
			else if(MAP[tx][ty] == 'X') {
				isVisit[tx][ty] = 2;
				MAP[tx][ty] = tc;
				days[tx][ty] = day + 1;
				q.push(make_pair(tx, ty));
			}
			else if(MAP[tx][ty] != tc ) {
				return day + days[tx][ty];
			}
	}}
	return -1;
}

int makeWt(pii XY){
	// cout << "LOG WT\n";
	queue<pii> tq;
	tq.push(XY);
	while(!tq.empty()){
		txy = tq.front(); tq.pop();
		for(int i = 0; i < 4; i++){
			tx = txy.X + dx[i]; ty = txy.Y + dy[i];
			     if(isVisit[tx][ty] > 0 || (tx < 1 || ty < 1 || tx > C || ty > R)) { continue; }
			else if(MAP[tx][ty] == '.') { tq.push(make_pair(tx, ty)); isVisit[tx][ty] = 1; }
			else if(MAP[tx][ty] == 'X') { MAP[tx][ty] = '.'; q.push(make_pair(tx, ty)); isVisit[tx][ty] = 1; }
			else if(MAP[tx][ty] == 'S' || MAP[tx][ty] == 'E') { return makeSwan(make_pair(tx,ty)); }
	}}
	return -1;
}

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
	ti = makeSwan(swans[0]);
	if(ti + 1){
		cout << 1 << '\n';
		// cout << "end at first \n";
		return 0;
	}
	makeSwan(swans[1]);
	
	// printMap();
	
	while(!q.empty()){
		txy = q.front(); q.pop();
		if(isVisit[txy.X][txy.Y] == 0){ makeWt(txy); continue; }
		
		int day = days[txy.X][txy.Y];
		int vsit = isVisit[txy.X][txy.Y];
		char tc = MAP[txy.X][txy.Y];
		for(int i = 0; i < 4; i++){
			tx = txy.X + dx[i]; ty = txy.Y + dy[i];
			     if(isVisit[tx][ty] == 1 || tx < 1 || ty < 1 || tx > C || ty > R ){ continue; }
			else if(MAP[tx][ty] == '.') {
				MAP[tx][ty] = tc;
				isVisit[tx][ty] = 2;
				days[tx][ty] = day;
				ti = makeSwan(make_pair(tx, ty));
				if(ti + 1){
					cout << (ti + 1) / 2 << '\n';
					// cout << "end at second\n";
					return 0; }
			}
			else if(MAP[tx][ty] == 'X') {
				MAP[tx][ty] = tc;
				isVisit[tx][ty] = vsit;
				days[tx][ty] = day + 1;
				q.push(make_pair(tx, ty));
			}
			else if(tc == '.'){
				ti = makeSwan(make_pair(tx, ty));
				if(ti + 1){
					// printMap();
					cout << (ti + 1) / 2 << '\n';
					// cout << "end at third\n";
					return 0; }
			}
			else if(MAP[tx][ty] != tc){
				// printMap();
				cout << (days[tx][ty] + day + 1) / 2 << '\n';
				// cout << "end at fourth: " << MAP[tx][ty] << ' ' << tc << "\n";
				return 0;
			}
		}
	}
	
}