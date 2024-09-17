#include <iostream>
#include <deque>
#define pii pair<int, int>
#define X first
#define Y second

using namespace std;

deque<pii> dq;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int N, L, temp;
	cin >> N >> L;
	
	for(int i = 0; i < N; i++){
		cin >> temp;
		while(!dq.empty() && dq.back().X > temp) dq.pop_back();
		dq.push_back(make_pair(temp, i));
		while(dq.front().Y <= i - L) dq.pop_front();
		cout << dq.front().X << " ";
	}
}