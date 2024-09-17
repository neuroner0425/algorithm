#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#define pii pair<int,int>
using namespace std;


string str = "ab";
int ss = str.size();

void func(long long i){
	char sa = str[ss - 1];
}

int main() {
    clock_t start, finish;
    double duration;
 
    start = clock();
    
    for(long long i = 0; i < 300000000; i++){
		func(i);
	}
 
    finish = clock();
 
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << duration << "초" << endl;
 
    return 0;
}