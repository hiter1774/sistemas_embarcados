#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int v_global = 0; // Variavel global para este exemplo

void Incrementa_Variavel_Global(pid_t id_atual)
{
	v_global++;
	printf("ID do processo que executou esta funcao = %d\n", id_atual);
	printf("v_global = %d\n", v_global);
  }

int main ()
{
	for (int i = 0; i < 3; ++i) 
	{
	    int pid = fork();
	    if(pid < 0)
	        exit(EXIT_FAILURE);
	    else if(pid == 0)   	
	        exit(EXIT_SUCCESS);
	}

	for (int i = 0; i < 3; ++i) 
	{
	    int status;
	    pid_t pid = wait(&status);
	    Incrementa_Variavel_Global(pid);
	}

	return 0;
}
