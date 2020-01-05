#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

#define BUFFER_SIZE 256
int main(){

	pid_t child1;
	
	int tube1[2];
	int tube2[2];
	char bufferR[BUFFER_SIZE], bufferW[BUFFER_SIZE];
	
	if(pipe(tube) != 0) {
		fprintf(stderr, "Error can't create pipe\n");
		exit(1);
	}
	
	child1 = fork();        
	if (child1 > 0){
			close(tube[0]);	
			sprintf(bufferW,"Hello Kid %d, I am your father %d", child1, getpid());
			write(tube[1], bufferW, BUFFER_SIZE);
			wait(NULL);
	}
	else{	
			close(tube[1]);
			read(tube[0], bufferR, BUFFER_SIZE);
			printf("I am child2 \"%d\", my father said \"%s\"\n", getpid(), bufferR);
				
		}
	
	return 0;

}

