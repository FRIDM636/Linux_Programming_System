#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


int main(int argc, char **argv)
{
  int status;
  int i;
  char *cat_args[] = {"cat", "out.txt", NULL};
  char *grep_args[] = {"grep", "o", NULL};
  char *cut_args[] = {"cut", "-b", "1-2", NULL};


  int pipes[4];
  pipe(pipes); // sets up 1st pipe
  pipe(pipes + 2); // sets up 2nd pipe

  
  if (fork() == 0) {
      dup2(pipes[1], 1);
      close(pipes[0]);
      close(pipes[1]);
      close(pipes[2]);
      close(pipes[3]);

      execvp(*cat_args, cat_args);
    }
  else
    {

      if (fork() == 0)
	{
	  
	  dup2(pipes[0], 0);
	  dup2(pipes[3], 1);
	  close(pipes[0]);
	  close(pipes[1]);
	  close(pipes[2]);
	  close(pipes[3]);

	  execvp(*grep_args, grep_args);
	}
      else
	{

	  if (fork() == 0)
	    {

	      dup2(pipes[2], 0);
	      close(pipes[0]);
	      close(pipes[1]);
	      close(pipes[2]);
	      close(pipes[4]);

	      execvp(*cut_args, cut_args);
	    }
	}
    }
      
return 0;
}
