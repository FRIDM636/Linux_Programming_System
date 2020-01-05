#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>

int main(){

	pid_t child1;
	pid_t child2;
	time_t time_start, time_end;
	printf("Main process \"%d\"\n",getpid());
	time_start = time(NULL);
	child1 = fork();        
	if (child1 > 0){
		child2 = fork();
		if(child2 > 0)
		{
			printf("I am father \"%d\"\n",getpid());
			wait(NULL);
			wait(NULL);
			time_end = time(NULL);
			printf("Passed time is %ld second\n",time_end - time_start);
		}
		else
		{	
				printf("I am child2 \"%d\", my father \"%d\"\n",getpid(),getppid());
				sleep(3);
				//exit(2)
		}
			}
	else {
				printf("I am child1 \"%d\", my father \"%d\"\n",getpid(),getppid());
				sleep(7);
				
	     }
		
	
	return 0;

}

