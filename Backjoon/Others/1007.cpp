#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#define INF 1000000001
#define pii pair<int, int>

using namespace std;

int N, tN, xV[21], yV[21];
double minV;

double get_dist(pii xy) { return sqrt(pow(xy.first, 2) + pow(xy.second, 2)); }

void dfs(int deep, int accuChoice, pii accuVector){
	if(N - deep == tN - accuChoice){
		for(int i = deep + 1; i <= N; i++){
			accuVector.first += xV[i];
			accuVector.second += yV[i];
		}
		minV = min(minV, get_dist(accuVector));
	}else if(accuChoice == tN){
		for(int i = deep + 1; i <= N; i++){
			accuVector.first -= xV[i];
			accuVector.second -= yV[i];
		}
		minV = min(minV, get_dist(accuVector));
	}else if(deep == N){
		minV = min(minV, get_dist(accuVector));
	}else{
		dfs(deep + 1, accuChoice + 1, make_pair(accuVector.first + xV[deep + 1], accuVector.second + yV[deep + 1]));
		dfs(deep + 1, accuChoice, make_pair(accuVector.first - xV[deep + 1], accuVector.second - yV[deep + 1]));
	}
}

// int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(10);

    int tc;
    cin >> tc;

    while (tc--)
    {
        cin >> N;
		tN = N / 2;
		minV = INF;
        for (int i = 1; i <= N; i++)
        {
            cin >> xV[i] >> yV[i];
        }
		dfs(1, 1, make_pair(xV[1],yV[1]));
        cout << minV << "\n";
    }

    return 0;
}
