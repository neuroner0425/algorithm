#include <iostream>
#include <vector>

#define pii pair<int, int>
#define ll long long
#define X first
#define Y second

using namespace std;

vector<pii> vt;
pii temp;
int N, a, b, endPoint;
long long K, now;

int getLength(int x){
	int sum = 0;
	for(int i = 0; i < N; i++)
		if(vt[i].Y >= x && vt[i].X < x) sum++;
	return sum;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> K;
	
	for(int i = 0; i < N; i++){
		cin >> a >> b;
		endPoint = (b > endPoint) ? b : endPoint;
		vt.push_back(make_pair(a, b));
	}
	a = b = 0;
	
	while(now != K){
		if(now < K){
			b++;
			if(b > endPoint){
				cout << "0 0\n"; return 0;
			}
			now += getLength(b);
		}else{
			a++;
			now -= getLength(a);
		}
	}
	
	cout << a << " " << b << "\n";
}