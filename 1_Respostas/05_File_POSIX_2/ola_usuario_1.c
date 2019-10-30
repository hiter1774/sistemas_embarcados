#include <stdio.h>	// Para a funcao printf()
	#include <fcntl.h>	// Para a funcao open()
	#include <unistd.h>	// Para a funcao close()
	#include <string.h>

	int main(int argc, const char * argv[])
	{
		char Nome[50], FileName[53], Buffer[100] = "Nome: ", str[10];
		int idade;

		printf("Digite o seu nome: ");
		scanf("%s", Nome);
		printf("Digite a sua idade: ");
		scanf("%d", &idade);
		strcpy(FileName, Nome);
		strcat(FileName, ".txt");

		strcat(Buffer, Nome);
		strcat(Buffer, "\nIdade: ");
		sprintf(str, "%d", idade);
		strcat(Buffer, str);
		strcat(Buffer, "\n\0");

		write(open (FileName, O_WRONLY | O_CREAT, S_IRWXU), Buffer, 50);

		return 0;
	}
