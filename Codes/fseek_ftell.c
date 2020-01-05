#include<stdio.h>
#include<stdlib.h>


int main(){
	
	FILE * f = fopen("file_pointer.txt","r");
	int i;
	if(!f){
		perror("Can't read the file");
		exit(1);
	}

	printf("The first 10 bytes are:\n"); 
	fseek(f,0,SEEK_SET);
	for(i = 0; i<10; i++){
		putchar(getc(f));
		
	}
	putchar('\n');
	
	printf("The last 10 bytes are:\n"); 
	fseek(f,-11,SEEK_END); //to prevent printing end of file EOF
	for(i = 0; i<10; i++){
		putchar(getc(f));
	}
	putchar('\n');
	
	fseek(f,0,SEEK_END);
	int middle = ftell(f)/2;
	printf("Number of bytes in file are: %d\n", middle*2); 
	

	printf("The 10 th  middle bytes using SEEK_SET are:\n");
	fseek(f,middle-5,SEEK_SET);
	for(i = 0; i<10; i++){
		putchar(getc(f));
	}
	putchar('\n');
	
	printf("The 10 th  middle bytes using SEEK_END are:\n"); 
	fseek(f,-middle-5-1,SEEK_END);//-1 because there is an EOF 
	for(i = 0; i<10; i++){
		putchar(getc(f));
	}
	putchar('\n');
	fclose(f);
	
	return 0;
}
