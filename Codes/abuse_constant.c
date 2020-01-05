#include<stdio.h>


int main() {
	const int var = 5;
	int const * const ptr = &var;
	int *p = &var;
	*p = 50;
	printf("Constant is changed! : %d\n",var);
		
	return 0;
}
