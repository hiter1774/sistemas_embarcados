        #include <stdio.h>
	#include <stdlib.h>
	#include "bib_arqs.h"

	int main(int argc, char *argv[])
	{
              char *String = (char*)malloc(tam_arq_texto(argv[1])+1);
		le_arq_texto (argv[1], String);
		printf("%s", String);
		return 0;
	}
