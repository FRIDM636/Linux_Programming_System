#include<stdio.h>

unsigned long long fact(unsigned long long n) {

	if (n <= 1)
		return 1;
	else 
		return n*fact(n-1);
}

int main() {
	
	unsigned long long int n = 1;
	printf("Enter a number fo factorial Calculs:\n");
	scanf("%lld",&n);
	printf("Factorial of \"%llu\" is: \"%llu\"\n",n,fact(n));

	return 0;
}
