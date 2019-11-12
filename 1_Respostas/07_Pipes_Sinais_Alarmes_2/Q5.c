#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void acabou(int sig)
{
	printf("Processo terminado!\n");
	exit(0);
}

void tratamento_alarme(int sig)
{
	system("ps --sort -time");
	alarm(1);
}

int main()
{
	signal(SIGALRM, tratamento_alarme);
	signal(SIGINT,acabou);
	alarm(1);
	printf("Aperte CTRL+C para acabar:\n");
	while(1);
	return 0;
}
