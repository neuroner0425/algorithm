#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

bool cmpf(pii &a, pii &b){ return a.first < b.first; }
struct cmps{ bool operator()(pii &a, pii &b) const{ return a.second > b.second; } };

int main(){
    int result = 0;
    int temp1, temp2, C, N;
    deque<int> chickenTime;
    deque<pii> cowTime;
    priority_queue<pii, vector<pii>, cmps> cq;

    ios::sync_with_stdio(0); cin.tie(0);

    cin >> C >> N;

    for(int i = 0; i < C; i++){
        cin >> temp1;
        chickenTime.push_back(temp1);
    }
    for(int i = 0; i < N; i++){
        cin >> temp1 >> temp2;
        cowTime.push_back({temp1, temp2});
    }
    
    sort(chickenTime.begin(), chickenTime.end());
    sort(cowTime.begin(), cowTime.end(), cmpf);

    while (!chickenTime.empty())
    {
        int time = chickenTime.front(); chickenTime.pop_front();
        while(!cowTime.empty() && cowTime.front().first <= time){
            cq.push(cowTime.front());
            cowTime.pop_front();
        }
        while(!cq.empty() && cq.top().second < time){
            cq.pop();
        }
        if(!cq.empty()){
            ++result;
            cq.pop();
        }
    }
    cout << result << "\n";
    return 0;
}