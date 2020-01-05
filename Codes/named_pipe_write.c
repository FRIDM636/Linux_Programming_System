#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFSIZE 512
#define err(mess) { fprintf(stderr,"Error: %s.", mess); exit(1); }

void main()
{
    int fd;
    ssize_t n;

    char *buf=malloc(sizeof(char));


    mkfifo("fifo_x", 0666);
    if ( (fd = open("fifo_x", O_WRONLY)) < 0)
        err("open")

    while( (n = read(STDIN_FILENO, buf, BUFFSIZE) ) > 0) {
	printf("Buf_len:%ld, ssize: %ld\n",strlen(buf),n);
        if ( write(fd, buf, n) != n) { 
            err("write");
        }
	
    }
    close(fd);
}
