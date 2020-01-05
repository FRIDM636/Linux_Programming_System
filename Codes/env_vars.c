#include<stdio.h>
#include<stdlib.h>

int main(){
	char *home, *path, new[150];
	home = getenv("HOME");
	path = getenv("PATH");
	
	printf("Old PATH: %s\nOld Home: %s\n",path,home);
	sprintf(new, "PATH=%s:%s /bin",path,home);
	putenv(new);
	printf("New PATH: %s\n",getenv("PATH"));

	return 0;
}
