#include "Num_Caracs.h"


int Num_Caracs(char *string)
{
  int numero = 0;

  while (string[numero] != '\0')
  {
    numero++;
  }

  return numero;
}
