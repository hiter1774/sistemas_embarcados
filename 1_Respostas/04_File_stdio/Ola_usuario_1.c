#include<stdio.h>

	int main()
	{
		char Nome[50], buf[0x100];
		int idade;

		printf("Digite o seu nome: ");
		scanf("%s", Nome);
		printf("Digite a sua idade: ");
		scanf("%d", &idade);

		snprintf(buf, sizeof(buf), "%s.txt", Nome);
		FILE *fp = fopen(buf, "w");

		fprintf(fp, "Nome: %s\nIdade: %d\n", Nome,  idade);
		return 0;
	}
