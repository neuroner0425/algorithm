#include <iostream>
#include <string>
#define pii pair<int,int>
#define MAX_RESULT 200

bool isOn[10][10], isOn_temp[10][10];
int dx[5] = {0, -1, 0, 1, 0}, dy[5] = {0, 0, 1, 0, -1}, result = MAX_RESULT;

using namespace std;

void copyArr(){
	for(int j = 0; j < 10; j++)
		for(int i = 0; i < 10; i++)
			isOn[i][j] = isOn_temp[i][j];
}

void turn(int x, int y){
	for(int i = 0; i < 5; i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx > 9 || ny > 9) continue;
		isOn[nx][ny] = !isOn[nx][ny];
	}
}

int main(){
	bool isDone = true;
	cin.tie(0); ios::sync_with_stdio(0);
	
	for(int j = 0; j < 10; j++){
		string temp;
		cin >> temp;
		for(int i = 0; i < 10; i++){
			isOn_temp[i][j] = (temp[i] == 'O');
		}
	}
	
	for(int fLine = 0; fLine < (1 << 10); fLine++){
		bool isDone = true;
		int tempResult = 0;
		copyArr();
		for(int bit = 0; bit < 10; bit++){
			if(fLine & (1 << bit)){
				turn(bit, 0);
				tempResult++;
			}
		}
		for(int line = 1; line < 10; line++){
			for(int bit = 0; bit < 10; bit++){
				if(isOn[bit][line - 1]){
					turn(bit, line);
					tempResult++;
				}
			}
		}
		
		for(int bit = 0; bit < 10; bit++){
			if(isOn[bit][9]){
				isDone = false;
			}
		}
		if(isDone){
			result = (tempResult < result) ? tempResult : result;
		}
	}
	
	if(result != MAX_RESULT){
		cout << result << '\n';
	}else{
		cout << 0 << '\n';
	}
}