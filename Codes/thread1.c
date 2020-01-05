#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<pthread.h>
void* func_thread(void* args){

	int sec = (int)args;
	printf("I am thread and I wait %d seconds\n",sec);
	sleep(sec);
	puts("I am thread, I finished my job");
	pthread_exit(NULL);
}


int main() {

	int ret;
	pthread_t thread;
	int sec;
	time_t t1;

	srand(time(NULL));
	t1 = time(NULL);

	sec = rand()%10;

	if(pthread_create(&thread,NULL, func_thread, (void*)sec) != 0) {
		fprintf(stderr, "Error creating thread\n");
		exit(1);
	}

	pthread_join(thread, NULL);
	printf("In main %d seconds\n",sec);
	printf("Passed time is %ld\n",time(NULL)-t1);

	return 0;
}


