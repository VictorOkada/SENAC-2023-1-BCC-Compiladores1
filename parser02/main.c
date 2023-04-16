#include <stdio.h>
#include <stdlib.h>
#include "tinyexpr.h"

int main(int argc, char *argv[])
{
  FILE *fp;
  char *line = NULL;        ////// VARIAVEIS UTILIZADAS PARA  ///////
  size_t len = 0;           ////// LEITURA DE entrada.txt     /////// 
  size_t read;
  //////////////////////////////////////////////////////////////////////////
  fp = fopen("entrada.txt", "r"); // abre arquivo entrada.txt
  if (fp == NULL) // valida se arquivo esta em branco
    exit(EXIT_FAILURE);
  
  while ((read = getline(&line, &len, fp)) != -1) 
  { // enquanto a linha do entrada.txt estiver preenchida
    printf("%f\n", te_interp("2 + 3! + 5", 0));
  }

  fclose(fp); // fecha arquivo entrada.txt
  
  if (line) // verifica cada linha preenchida
    free(line); // libera memoria
  exit(EXIT_SUCCESS); // sai do programa

}