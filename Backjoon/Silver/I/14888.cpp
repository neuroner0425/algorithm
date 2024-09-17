#include <iostream>

#define MAX 1000000001

using namespace std;

int n, resultHigh = -MAX, resultLow = MAX;
int arr[11], func[4];

void dfs(int deep, int value){
	if(deep == n){
		cout << value << "\n";
		if(value > resultHigh) resultHigh = value;
		if(value < resultLow) resultLow = value;
		return;
	}
	
	if(func[0] > 0){
		func[0]--;
		dfs(deep + 1, value + arr[deep]);
		func[0]++;
	}
	if(func[1] > 0){
		func[1]--;
		dfs(deep + 1, value - arr[deep]);
		func[1]++;
	}
	if(func[2] > 0){
		func[2]--;
		dfs(deep + 1, value * arr[deep]);
		func[2]++;
	}
	if(func[3] > 0){
		func[3]--;
		dfs(deep + 1, value / arr[deep]);
		func[3]++;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < 4; i++){
		cin >> func[i];
	}
	
	dfs(1, arr[0]);
	
	cout << resultHigh << "\n" << resultLow << "\n";
}