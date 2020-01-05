#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>

int main(int argc, char **argv){
	pid_t pidToSend;
	char rep;

	if(argc != 2) {
		fprintf(stderr, "Usage: %s process_pid\n",argv[0]);
		exit(1);
	}

	pidToSend = atoi(argv[1]);
	printf("Are you sure to kill process with pid \"%d\"? (y/n)\n",pidToSend);
	rep = getchar();
	if (rep == 'y')
		kill(pidToSend, SIGTERM);

	return 0;

}
	
