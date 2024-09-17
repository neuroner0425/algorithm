#include <iostream>
using namespace std;
bool c[42];
int main(){
	int temp;
	for(int i = 0; i < 10; i++){
		cin >> temp;
		c[temp % 42] = true;
	}
	temp = 0;
	for(int i = 0; i < 42; i++)
		if(c[i])
			temp++;
	cout << temp << "\n";
}