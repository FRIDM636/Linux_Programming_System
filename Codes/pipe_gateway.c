#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define BUFFER_SIZE 2048

int main(int argc, char **argv){

	
	char * cat_args[] = {"cat", "out.txt", NULL};
	char * grep_args[] = {"grep", "o", NULL};
	char * cut_args[] = {"cut", "-b","1-100", NULL};
	
	int n;
	unsigned char *Buffer_R = malloc(BUFFER_SIZE*sizeof(unsigned char)); 
	unsigned char *Buffer_W = malloc(BUFFER_SIZE*sizeof(unsigned char));
	
	int tube[4];
	pipe(tube);
	pipe(tube +2);
	/*
	if(pipe(tube) != 0 && pipe(tube+2) != 0)
	{
		fprintf(stderr,"Error creating pipes! \n");
		exit(1);
	 }*/
	        
	if (fork() == 0){
			dup2(tube[1],1);
			close(tube[0]);
			close(tube[2]);	
			close(tube[3]);
			sprintf(Buffer_W, "\"Hi I am Child 1; pid = %d, ppid = %d\"",getpid(),getppid());
			write(tube[1], Buffer_W, BUFFER_SIZE);
			close(tube[1]);
			
			}
		else {
			if(fork() == 0) {  //this is like a gateway
				dup2(tube[0],0);
				dup2(tube[3],1);
				close(tube[1]);	
				close(tube[2]);	
				read(tube[0], Buffer_R, BUFFER_SIZE); //read STDIN_FILENO in Buffer_W 
				sprintf(Buffer_W,"\"Hi I am Child 2; pid = %d, ppid = %d, message:\"\n%s\n",getpid(),getppid(),Buffer_R);
				close(tube[0]);
				write(tube[3], Buffer_W,BUFFER_SIZE); //write Buffer_W in STDOUT_FILENO
				close(tube[3]);	
			}
			else {
				
				dup2(tube[2],0); 
				close(tube[0]);	
				close(tube[1]);
				close(tube[3]);
				n=read(tube[2], Buffer_R, BUFFER_SIZE);
				printf("Hi I am Father %d I get this:\n",getpid());
				close(tube[2]);
				write(STDOUT_FILENO,Buffer_R,BUFFER_SIZE);
				wait(NULL);
				wait(NULL);
				wait(NULL);
				
				}
			}
			
		

	return 0;

}

