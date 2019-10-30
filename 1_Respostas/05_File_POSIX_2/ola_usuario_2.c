#include <stdio.h>	// Para a funcao printf()
	#include <fcntl.h>	// Para a funcao open()
	#include <unistd.h>	// Para a funcao close()
	#include <string.h>

	int main(int argc, char *argv[])
	{

		char Nome[50], FileName[53], Buffer[100] = "Nome: ";

		strcpy(FileName, argv[1]);
		strcat(FileName, ".txt");

		strcat(Buffer, argv[1]);
		strcat(Buffer, "\nIdade: ");
		strcat(Buffer, argv[2]);
		strcat(Buffer, "\n\0");

		write(open (FileName, O_WRONLY | O_CREAT, S_IRWXU), Buffer, 50);

		return 0;
	}
	
