#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>


int main(int argc, char ** argv) {
	char *current_path = getenv("PWD");
	printf("Current path: %s\n",current_path);
	char * command = malloc(sizeof(char)); //to avoid segmentation faults
	if( argc <= 1 || argc >2 )
		printf("Usage app path_to_directory\n");
	else   
		{
		char * distant_path = argv[1];
		printf("Distant path: %s\n",distant_path);
		sprintf(command,"cp -rf %s %s",distant_path,current_path);
		//strcpy(command,"cp -rf ");
		//strcat(command,distant_path);
		//strcat(command," ");
		//strcat(command,current_path);
		if(command[0] != '\0')
			{
			printf("Command: %s\n",command);
			system(command);
			printf("Successfully Copied!\n");
			}
		else
			printf("Failed Copying!\n");
		}
	free(command);
	return 0;
}
