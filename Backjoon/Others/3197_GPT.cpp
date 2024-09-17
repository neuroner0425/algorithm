#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int R, C;
char lake[1500][1500];
int visited[1500][1500];
int water_day[1500][1500]; // 얼음이 녹는 날을 기록
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int>> water_queue;
vector<pair<int, int>> swans;

// 물이 얼음을 녹이는 과정
void melt_ice() {
    while (!water_queue.empty()) {
        int x = water_queue.front().first;
        int y = water_queue.front().second;
        water_queue.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if (water_day[nx][ny] != -1) continue;
            if (lake[nx][ny] == 'X') {
                water_day[nx][ny] = water_day[x][y] + 1;
                water_queue.push({nx, ny});
            }
        }
    }
}

// 두 백조가 만날 수 있는지 확인하는 BFS
bool can_meet(int day) {
    queue<pair<int, int>> q;
    q.push(swans[0]);
    visited[swans[0].first][swans[0].second] = 1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if (visited[nx][ny]) continue;
            
            // 다른 백조를 만난 경우
            if (nx == swans[1].first && ny == swans[1].second) return true;
            
            // 현재 날짜에 갈 수 있는 위치
            if (lake[nx][ny] == '.' || (lake[nx][ny] == 'X' && water_day[nx][ny] <= day)) {
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    
    return false;
}

int main() {
    cin >> R >> C;
    
    for (int i = 0; i < R; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < C; j++) {
            lake[i][j] = row[j];
            water_day[i][j] = -1;
            if (lake[i][j] == 'L') {
                swans.push_back({i, j});
                water_queue.push({i, j});
                water_day[i][j] = 0;
            } else if (lake[i][j] == '.') {
                water_queue.push({i, j});
                water_day[i][j] = 0;
            }
        }
    }
	
    melt_ice();
    
    int left = 0, right = 1500;
    int answer = 1500;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        fill(&visited[0][0], &visited[0][0] + 1500 * 1500, 0);
        
        if (can_meet(mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << answer << '\n';
    
    return 0;
}
