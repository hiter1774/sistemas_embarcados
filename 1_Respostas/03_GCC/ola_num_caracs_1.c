#include <stdio.h>
#include "Num_Caracs.h"


int main (int argc, char **argv)
{
  int i;
  int tamanho[argc-1];


for(i = 0; i < argc ; i++){

  tamanho[i] = Num_Caracs(argv[i]);

 printf("Argumentos: %s / Numero de caracteres: %d \n", argv[i], tamanho[i]);
 }

  return 0;
}
