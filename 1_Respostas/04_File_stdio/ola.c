#include<stdio.h>

	int main()
	{
		FILE * fp = fopen("Ola_mundo.txt", "w");
		fputs("Ola mundo!\n", fp);
		fclose(fp);
		return 0;
	}
