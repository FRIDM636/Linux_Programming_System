#include<stdio.h>


int main() {


	int a = 5;
	int b = 6;
	int c = -1;
	int d = 0;
	
	printf("a= 5, b=6,  a&&b = %d\n",a && b);
	printf("a= 5, b=-1, a&&c = %d\n",a && c);
	printf("c= -1, b=6, c&&b = %d\n",c && b);
	printf("c= -1, d=0, c&&d = %d\n",c && d);

	return 0;

}
