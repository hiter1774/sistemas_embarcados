#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd[2];
    char m[4][100] = {"Pai, qual é a verdadeira essência da sabedoria? ",
    				  "Não façais nada violento, praticai somente aquilo que é justo e equilibrado.",
    				  "Mas até uma criança de três anos sabe disso!",
    				  "Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu..."}, s[100];
    pipe(fd);
    pid_t pid = fork();

    if (pid != 0)
    	for(int i = 0 ; i < 2 ; i++)
    	{
    		write(fd[1], m[2*i], sizeof(m[0]));
	    	sleep(1);
	    	if(read(fd[0], s, 100)>=0)
	    		printf("PAI: %s\n", s);
    	}
    else
    	for(int i = 0 ; i < 2 ; i++)
    	{
	    	if(read(fd[0], s, 100)>=0)
	    		printf("FILHO: %s\n", s);
	    	write(fd[1], m[2*i+1], sizeof(m[0]));
	    	sleep(1);
    	}
    return 0;
}
