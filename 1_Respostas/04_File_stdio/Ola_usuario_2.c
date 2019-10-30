	#include<stdio.h>
	#include<stdlib.h>

	int main(int argc, char *argv[])
	{
		char buf[0x100];

		snprintf(buf, sizeof(buf), "%s.txt", argv[1]);
		FILE *fp = fopen(buf, "w");

		fprintf(fp, "Nome: %s\nIdade: %d\n", argv[1],  atoi(argv[2]));
		fclose(fp);
		return 0;
	}
