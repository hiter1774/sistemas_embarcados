#include <stdio.h>

int main (int argc, char **argv)
{
  int i;

printf("Argumentos:");

for(i = 1; i <= (argc - 1); i++){
  
  printf(" %s", argv[i]);
 }

printf("\n");
  return 0;
}
