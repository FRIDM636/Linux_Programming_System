#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>

int main(int argc, char ** argv){

	struct stat st;
	struct tm * temps;

	if(argc != 2) {
		fprintf(stderr,"Usage: %s file_name\n",argv[0]);
		exit(0);
	}

	if(stat(argv[1], &st) != 0) {
		perror("File acces error !");
		exit(1);
	}

	if(S_ISDIR(st.st_mode))
		printf("This \"%s\" is a direcotry name!\n",argv[1]);

	if(S_ISREG(st.st_mode)) {
		printf("\"%s\" is an ordinary file\n",argv[1]);
		printf("Size of file is: \"%ld\" bytes\n",st.st_size);
		temps = localtime(&st.st_mtime);
		printf("Last modification is: \"%d/%d/%d\"\n",(*temps).tm_mday, (*temps).tm_mon +1, (*temps).tm_year + 1900);
	}
	return 0;

}
