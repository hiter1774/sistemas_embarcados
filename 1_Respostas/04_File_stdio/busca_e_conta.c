	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "bib_arqs.h"

	int main(int argc, char *argv[])
	{
		char *String = (char*) malloc(tam_arq_texto(argv[2])+1);
		char *T = (char*) malloc(tam_arq_texto(argv[2])+1);
		le_arq_texto(argv[2], String);

		int i, j=0, q=0;
		for(i = 0; i <= strlen(String)-strlen(argv[1]) ; i++)
			if(String[i] == argv[1][0])
			{
				while(String[i+j] == argv[1][j])
				{
					j++;
					if(j == strlen(argv[1])-1 )
					{
						q++;
						break;
					}
				}
				j = 0;
			}

		printf("'%s' ocorre %d vezes no arquivo '%s'", argv[1], q, argv[2] );
		return 0;
	}
