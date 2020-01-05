#include<stdio.h>



void fib(int x) {
	int i;
	int u1=0, u2=1,tmp;
	for(i = 0;i<=x;i++){
		printf("%d ",u2);
		tmp = u2;
		u2 = u2 + u1;
		u1 = tmp;
	}
	printf("\n");
}


int main(){
	int n = 0;
	printf("Enter a number of fibonnaci series:\n");
	scanf("%u",&n);
	printf("Fibonaci numbers are:\n");
	fib(n);

	return 0;
}
