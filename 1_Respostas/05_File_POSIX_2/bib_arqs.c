        #include <stdio.h>
	#include <fcntl.h>
	#include <unistd.h>

	int tam_arq_texto(char *nome_arquivo)
	{
		return lseek( open (nome_arquivo, O_RDONLY) , 0, SEEK_END);
	}

void le_arq_texto(char *nome_arquivo, char *conteudo)
	{
		read(open (nome_arquivo, O_RDONLY), conteudo, tam_arq_texto(nome_arquivo));
	}

