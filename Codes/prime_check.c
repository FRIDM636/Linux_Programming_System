#include<stdio.h>

int main(){
	int p;
	printf("Please Enter your test case number:\n");
	scanf("%d",&p);
	int i = 2;
	while(p%i != 0 && p != 2)
			i++;
	if(i > p/2 | p == 2)
		printf("Your number \'%d\' is a prime number.\n",p);
	else
		printf("Your number \'%d\' is not a prime number.\n",p);
	
	printf("Done!.\n");
	return 0;
}
