#include <stdio.h>

int main(){
	int tc, n;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d", &n);
		if(n % 2) printf("E");
		else printf("O");
	}
}