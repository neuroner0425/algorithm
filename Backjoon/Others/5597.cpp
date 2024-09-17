#include <iostream>
using namespace std;
bool c[31];
int main(){
	int temp;
	for(int i = 0; i < 28; i++){
		cin >> temp;
		c[temp] = true;
	}
	for(int i = 1; i <= 30; i++)
		if(!c[i])
			cout << i << "\n";
}