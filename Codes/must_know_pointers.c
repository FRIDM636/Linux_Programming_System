#include<stdio.h>

int main() {
	
	int x = 5;

	int * p = &x;

	int ** r = &p;

	printf("Address of p: %p\n",&p);
	printf("Address of p by r: %p\n",r);
	printf("Address of x: %p\n",&x);
	printf("Address of x by p: %p\n",p);
	printf("Address of x by *r: %p\n",*r);
	printf("Value of x by *p: %d\n",*p);
	printf("Value of x  by **r: %d\n",**r);
	return 0;
}
