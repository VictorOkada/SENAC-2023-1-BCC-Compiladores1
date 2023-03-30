#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define NAMES C(MAIS)C(MENOS)C(MULTIPLICACAO)C(DIVIDIR)C(INDETERMINADO)C(POTENCIA)
#define C(x) x,
enum color { NAMES TOP };
#undef C

#define C(x) #x,    
const char * const color_name[] = { NAMES };


void tokenizar(char *str)
{
    const char *resposta1 = color_name[ MAIS ];
    const char *resposta2 = color_name[ MENOS ];
    const char *resposta3 = color_name[ MULTIPLICACAO ];
    const char *resposta4 = color_name[ DIVIDIR ];
    const char *resposta5 = color_name[ INDETERMINADO ];
    const char *resposta6 = color_name[ POTENCIA ];
  
    for (int i = 0; str[i] != '\0'; i++) 
    {
    
      switch(str[i])
      {
        case '+':
          printf("  %s,\n", resposta1);
          break;
        
        case '-':
          printf("  %s,\n", resposta2);
          break;
        
        case '*':
      
          if(str[i] == str[i + 1])  printf("  %s,\n", resposta6); // se caractere proximo for igual ao atual, entao retorna potencia
          if(str[i] != str[i + 1])  printf("  %s,\n", resposta3); // se caractere proximo for diferente do caractere atual retorna multiplicacao
          
          i = i + 1; // avanca um caractere para nao haver impressao repetida
          break;
          
        case '/':
          printf("  %s,\n", resposta4);
          break;
        
        case ' ':
          break;
        
        default:
          printf("  %s,\n", resposta5);
      }
     
    }
    
}

int main(void)
{
  FILE *fp;
  char *line = NULL;        ////// VARIAVEIS UTILIZADAS PARA  ///////
  size_t len = 0;           ////// LEITURA DE entrada.txt     /////// 
  size_t read;
  //////////////////////////////////////////////////////////////////////////
  fp = fopen("entrada.txt", "r"); //abre arquivo entrada.txt
  if (fp == NULL) //valida se arquivo esta em branco
    exit(EXIT_FAILURE);
  
  while ((read = getline(&line, &len, fp)) != -1) 
  { // enquanto a linha do entrada.txt estiver preenchida
   
    printf("TOKENS: [\n\n");
    tokenizar(line);
    printf("\n]");
      
  }

  fclose(fp); // fecha arquivo entrada.txt
  
  if (line) // verifica cada linha preenchida
    free(line); //libera memoria
  exit(EXIT_SUCCESS); //sai do programa

}

/* REFERENCIAS

//https://stackoverflow.com/questions/9907160/how-to-convert-enum-names-to-string-in-c
//https://www.geeksforgeeks.org/c-program-to-extract-characters-from-a-string/

*/