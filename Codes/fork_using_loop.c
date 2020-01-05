#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>

int main(){
	time_t  t_begin;
	time_t  t_end;
	int i;
	t_begin = time(NULL);
	pid_t = getpid()
	for(i = 0; i <2; i++)
		{	
				
			if(!(fork()))
				{
				printf("I am child \"%d\" with pid \"%d\", my father \"%d\"\n",i,getpid(),getppid());
				sleep(5);	
				break;
				}
				
							
		}
		
	if(getpid() == pid)
		{
		wait(NULL);
		time_end = time(NULL);
		printf("Passed time is %ld seconds\n",t_end-t_begin);
		}
		

	return 0;
}
