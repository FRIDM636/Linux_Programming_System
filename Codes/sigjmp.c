#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<setjmp.h>

int x,y,z;
sigjmp_buf env;

void handler_proc(int number) {
	FILE *fp;
	int i;

	if(number == SIGFPE)
	{
		printf("Float calculation \n");
		printf("Enter a number different than 0 \n");
		scanf("%d", &y);
		siglongjmp(env, 1);
		
	}
}	

int main(int argc, char **argv){
	
	int i;
	struct sigaction action;
	
	action.sa_handler = handler_proc;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;

	if(sigaction(SIGFPE, &action, NULL) != 0) {
		fprintf(stderr, "Error in sigaction\n");
		exit(1);
	}

	
	printf("Enter x and y:");
	scanf("%d%d", &x, &y); 
	sigsetjmp(env, 1);
	z = x/y;
	printf("%d/%d=%d\n",y,x,z);

	return 0;

}
	
