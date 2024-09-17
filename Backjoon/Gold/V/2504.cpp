#include <iostream>
#include <stack>
#include <string>

#define pci pair<char, int>
#define C first
#define I second

using namespace std;

int ti;
char temp;
string str;
stack<pci> st;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	string semple = "([])";
	
	cin >> str;
	
	st.push(make_pair('N', 0));
	
	for(int i = 0; i < str.length(); i++){
		// cout << i << ": ";
		temp = str[i];
		if(temp == semple[0])
			st.push(make_pair(temp, 0));
		else if(temp == semple[1])
			st.push(make_pair(temp, 0));
		else if(temp == semple[2]){
			if(st.top().C != semple[1]){
				cout << "0\n";
				return 0;
			}
			ti = st.top().I ? st.top().I : 1;
			st.pop();
			st.top().I += ti * 3;
		}else if(temp == semple[3]){
			if(st.top().C != semple[0]){
				cout << "0\n";
				return 0;
			}
			ti = st.top().I ? st.top().I : 1;
			st.pop();
			st.top().I += ti * 2;
		}
	}
	
	if(st.size() != 1){
		cout << "0\n";
		return 0;
	}
	
	cout << st.top().I << '\n';
}