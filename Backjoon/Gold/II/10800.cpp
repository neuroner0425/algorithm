#include <iostream>
#include <algorithm>
#include <tuple>

#define ll long long

using namespace std;

int N, sum, cPrefix[200001], ans[200001];

bool comp(tuple<int, int, int> &t1, tuple<int, int, int> &t2){
	if(get<1>(t1) != get<1>(t2)) return get<1>(t1) < get<1>(t2);
	return get<0>(t1) < get<0>(t2);
}

int main(){
	int tmp1, tmp2;
	tuple<int, int, int> arr[200001];
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> tmp1 >> tmp2;
		arr[i] = make_tuple(tmp1, tmp2, i);
	}
	
	sort(arr + 1, arr + N + 1, comp);
	
	// /*LOG*/ cout << "\n--AFTER SORT--\n";for(int i = 1; i <= N; i++){ cout << get<0>(arr[i]) << " " << get<1>(arr[i]) << " " << get<2>(arr[i]) << "\n"; } cout << "\n";
	
	for(int i = 1; i <= N; i++){
		int tempSum = 0, j = i;
		ans[get<2>(arr[j])] = sum - cPrefix[get<0>(arr[j])];
		tempSum += get<1>(arr[j]);
		while(get<1>(arr[j]) == get<1>(arr[j + 1]) && get<0>(arr[j]) == get<0>(arr[j + 1])){
			j++;
			ans[get<2>(arr[j])] = sum - cPrefix[get<0>(arr[j])];
			tempSum += get<1>(arr[j]);
		}
		cPrefix[get<0>(arr[j])] += get<1>(arr[j]) * (j - i + 1);
		i = j;
		
		while(get<1>(arr[i]) == get<1>(arr[i + 1])){
			i++; j = i;
			ans[get<2>(arr[j])] = sum - cPrefix[get<0>(arr[j])];
			tempSum += get<1>(arr[j]);
			while(get<1>(arr[j]) == get<1>(arr[j + 1]) && get<0>(arr[j]) == get<0>(arr[j + 1])){
				j++;
				ans[get<2>(arr[j])] = sum - cPrefix[get<0>(arr[j])];
				tempSum += get<1>(arr[j]);
			}
			cPrefix[get<0>(arr[j])] += get<1>(arr[j]) * (j - i + 1);
			i = j;
		}
		sum += tempSum;
	}
	// /*LOG*/ cout << "\n--ANSWER--\n";
	for(int i = 1; i <= N; i++){
		cout << ans[i] << "\n";
	}
}