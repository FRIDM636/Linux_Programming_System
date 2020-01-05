#include<stdio.h>
#include<stdarg.h>

int sum(int num,...) {
	va_list args;
	int sum=0, i;
	
	va_start(args, num);

	for(i = 0; i < num; i++)
		sum += va_arg(args, int);

	va_end(args);

	return sum;
}

int main(void) {
	printf("Sum of 1,2,3 is: %d\n",sum(3,1,2,3));
	return 0;
}
