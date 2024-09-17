#include <iostream>
#include <stack>

#define pli pair<long long, int>
#define X first
#define Y second

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, times; long long temp, ans = 0, ttt = 0;
	stack<pli> st;
	cin >> N;
	cin >> temp; st.push(make_pair(temp, 1)); N--; // 입력 대체
	while(N--){
		cin >> temp;
		times = 1;
		while(!st.empty() && st.top().X < temp){
			ans += st.top().Y;
			st.pop();
		}
		if(!st.empty() && st.top().X == temp){
			ans += st.top().Y;
			times = st.top().Y + 1;
			st.pop();
		}
		if(!st.empty()) ans++;
		ttt = ans;
		st.push(make_pair(temp, times));
	}
	cout << ans;
}