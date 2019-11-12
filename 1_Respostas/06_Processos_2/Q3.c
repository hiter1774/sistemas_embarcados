#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char **argv)
{
	char **p = (char **) malloc(argc*sizeof(char));

	for(int i = 0; i < argc ; i++)
		p[i] = argv[i+1];
	p[argc] = NULL;

	int pid = fork();
	if(pid < 0)
	    exit(EXIT_FAILURE);
	else if (pid == 0)
		execvp(p[0], p);

	return 0;
}

