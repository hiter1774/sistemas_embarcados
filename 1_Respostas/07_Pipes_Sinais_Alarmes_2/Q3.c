#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd[2];
    char m[3][100] = {"Quando o vento passa, é a bandeira que se move. ",
    				  "Não, é o vento que se move.",
    				  "Os dois se enganam. É a mente dos senhores que se move."}, s[100];
    pipe(fd);
    pid_t pid = fork();
    if(pid == 0)
    {
    	if(read(fd[0], s, 100) >= 0)
    		printf("FILHO1: %s\n", s);
    	exit(0);
    }
    else
    {
    	pid_t pid2 = fork();
    	if(pid2 == 0)
    	{
    		sleep(1);
	    	if(read(fd[0], s, 100) >= 0)
	    		printf("FILHO2: %s\n", s);
	    	write(fd[1], m[2], sizeof(m[0]));
    		exit(0);
    	}
    	else
    	{
    		write(fd[1], m[0], sizeof(m[0]));
    		sleep(1);
    		write(fd[1], m[1], sizeof(m[0]));
    		sleep(1);
    		if(read(fd[0], s, 100) >= 0)
    			printf("PAI: %s\n", s);
    		
    		exit(0);
    	}
    }
    return 0;
}
