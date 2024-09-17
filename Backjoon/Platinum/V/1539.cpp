#include <iostream>
#include <stack>
#include <algorithm>
#define ll long long

using namespace std;

int N;
ll H[100001];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> H[i];
	ll ret=0;
	stack<int> st;
	for (int i = 0; i < N; i++) {
		while (!st.empty() && H[st.top()] > H[i]) {
			int height = H[st.top()];
			st.pop();
			int width = i;
			if (!st.empty())
				width = i - st.top() - 1;
			ret = max(ret, (ll)height*width);
		}
		st.push(i);
	}
	while (!st.empty()) {
		int height = H[st.top()];
		st.pop();
		int width = N;
		if (!st.empty())
			width = N - st.top() -1;
		ret = max(ret, (ll)height*width);
	}
	cout << ret << "\n";
	return 0;
}