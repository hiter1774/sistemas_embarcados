#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd[2];
    char s[100], o[100];
    pipe(fd);
    pid_t pid = fork();

    if(pid == 0)
    {
    	printf("Escreva seu nome: ");
    	scanf("%[^'\n']", s);
    	write(fd[1], s, sizeof(s));
    }
    else
    {
    	while(read(fd[0], o, 100) < 0)
    	{}
    	printf("Nome do usuario: %s\n", o);
    }
    return 0;
}
