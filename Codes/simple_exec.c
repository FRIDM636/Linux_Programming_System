#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char ** argv) {
	
	if( argc <= 1 || argc >2 )
		printf("Usage app file_name.txt\n");
	else
		execl("/usr/bin/vi","vi",argv[1],NULL);
	return 0;
}
