#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

	pid_t child1;
	pid_t child2;
	pid_t g_child1;
	pid_t g_child2;
	printf("Main process \"%d\"\n",getpid());
	child1 = fork();        
	if (child1 > 0){
		child2 = fork();
		if(child2 > 0)
		{
			printf("I am father \"%d\"\n",getpid());
			wait(NULL);
		}
		else
		{	
			g_child2 = fork();
			if(g_child2 > 0)
			{
				printf("I am child2 \"%d\", my father \"%d\"\n",getpid(),getppid());
				wait(NULL);
			}
			else
				printf("I am grand_child2 \"%d\", my father \"%d\"\n",getpid(),getppid());
		}
			}
	else
	{
			g_child1 = fork();
			if(g_child1 > 0)
			{
				printf("I am child1 \"%d\", my father \"%d\"\n",getpid(),getppid());
				wait(NULL);
			}
			else
				printf("I am grand_child1 \"%d\", my father \"%d\"\n",getpid(),getppid());
		
	}
		
	
	return 0;

}

