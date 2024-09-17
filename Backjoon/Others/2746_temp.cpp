#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, arr[500001];

int bs_n(int *start, int *end, int num) {
	int low = 0;
	int high = end - start;
	int mid = 0;
	int temp;

	while (low <= high) {
		mid = (low + high) / 2;
		if (start[mid] < num) low = mid + 1;
		else high = mid - 1;
	}
	if (start[low] != num) return 0;
	temp = low;
	
	mid = low = 0;
	high = end - start;
	while (low <= high) {
		mid = (low + high) / 2;
		if (start[mid] <= num) low = mid + 1;
		else high = mid - 1;
	}
	if (start[high] != num) return 0;
	return high - temp + 1;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	long long sum = 0, res = 0;
	int temp;

	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		sum += arr[i];
	}
	
	sort(arr + 1, arr + n + 1);
	
	
	if(sum - arr[n] - arr[n-1] == 2 * arr[n-2]) res++;
	
	temp = bs_n(arr + 1, arr + n - 2, sum - arr[n] - arr[n - 1] * 2);
	if(temp > 0) res += temp;
	
	for(int i = 1; i < n - 1; i++){
		temp = bs_n(arr + i + 1, arr + n - 1, sum - arr[i] - arr[n] * 2);
		if(temp > 0) res += temp;
	}
	
	cout << res << "\n";
    return 0;

}