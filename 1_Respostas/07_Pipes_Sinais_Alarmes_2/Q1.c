#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd[2];
    int I, O[10];
    pipe(fd);
    pid_t pid = fork();

    if (pid != 0)
        for(int i = 0 ; i < 10 ; i++)
        {
	        I = i + 1;
	        write(fd[1], &I, sizeof(int));
	        sleep(1);
   		}

    else
    {  
        for(int i = 0 ; i < 10 ; i++)
	        if(read(fd[0], &O[i], sizeof(int))>=0)
	        	printf("%d ", O[i]);
	    exit(1);
    }
    return 0;
}
