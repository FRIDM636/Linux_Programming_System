#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

int data[5];

void handler_proc(int number) {
	FILE *fp;
	int i;

	if(number == SIGINT)
	{
		printf("\n Interruption \"^C\" signal\n");
		fp = fopen("/home/ij/Desktop/save.txt", "w");
		for(i = 0; i<5; i++)
			fprintf(fp,"%d ",data[i]);
		fprintf(fp,"\n");
		fclose(fp);
		printf(" Data safely saved!\n");
		exit(0);
	}
}	

int main(int argc, char **argv){
	
	int i;
	char c = 'n';
	struct sigaction action;
	
	action.sa_handler = handler_proc;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;

	if(sigaction(SIGINT, &action, NULL) != 0) {
		fprintf(stderr, "Error in sigaction\n");
		exit(1);
	}

	for( i = 0; i<5; i++) {
		printf("data[%d]= ", i);
		scanf("%d",&data[i]);
	}

	while(c != 'y') {
		puts(" zzz ...");
		sleep(1);
		for(i=0;i<5;i++)
			printf("data[%d] = %d\n",i,data[i]);
		printf("Quit? (y/n)\n");
		scanf(" %c",&c);
		printf("c=%c\n",c);
	}

	return 0;

}
	
