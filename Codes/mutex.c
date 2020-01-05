#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t v_mutex = PTHREAD_MUTEX_INITIALIZER;

void * func(void* args) {
	int thread_id = (int)args;
	int iterations, i, j, k, n;

	iterations = rand()%8;

	for(i = 0; i<iterations; i++){
		n = 10000;
		pthread_mutex_lock(&v_mutex);
		printf("Thread %d is calculating\n",thread_id);
		for(j = 0; j <n; j++)
			for(k = 0; k<n; k++)
			{}

	printf("Thread %d have finished calculations\n",thread_id);
	pthread_mutex_unlock(&v_mutex);
	}
	pthread_exit((void*)thread_id);
	}


int main() {
	int *ret = malloc(sizeof(int)); //avoid segmentation fault
	int i;
	pthread_t thread[10];
	srand(time(NULL));

	for(i=0; i<10; i++) 
		pthread_create(&thread[i],NULL, func, (void*)i);
	
	for(i=0; i<10; i++){
		pthread_join(thread[i],(void*)ret);
		printf("Thread %d is terminated\n",*ret);
		}
	free(ret);
	return 0;
	}
