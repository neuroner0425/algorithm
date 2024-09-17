#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N;
int result;
vector<pair<int, int>> queenExistLocation; // 이미 퀸이 존재하는 위치에 대한 배열

// 이미 존재하는 퀸으로부터 공격당하지 않는지 판별하는 메소드
bool canPutQueen(const int& row, const int& col) {
	for (pair<int, int> p : queenExistLocation) {
		int i = p.first;
		int j = p.second;

		// 같은 행 또는 같은 열 또는 대각선에 퀸이 이미 존재하면 false
		if (row == i || col == j || fabs(row - i) == fabs(col - j))
			return false;
	}
	
	return true;
}

void dfs(const int& row) {
	// 마지막 행까지 탐색이 되었다는 것은 조건을 만족하는 경우임
	if (N == row) {
		result++;
		return;
	}

	for (int j = 1; j <= N; j++) {
		// 다음 행 중에서 퀸을 배치할 수 있는 위치로만 DFS
		if (canPutQueen(row + 1, j)) {
			queenExistLocation.push_back(make_pair(row + 1, j));
			dfs(row + 1);
			queenExistLocation.erase(queenExistLocation.end() - 1);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	dfs(0);

	cout << result << '\n';

	return 0;
}