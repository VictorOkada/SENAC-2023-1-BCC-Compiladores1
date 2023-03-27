#include <stdio.h>
#include <string.h>

#define NAMES C(MAIS)C(MENOS)C(VEZES)C(DIVIDIR)C(INDETERMINADO)
#define C(x) x,
enum color { NAMES TOP };
#undef C

#define C(x) #x,    
const char * const color_name[] = { NAMES };


void tokenizar(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {

      char *resposta1 = color_name[ MAIS ];
      char *resposta2 = color_name[ MENOS ];
      char *resposta3 = color_name[ VEZES ];
      char *resposta4 = color_name[ DIVIDIR ];
      char *resposta5 = color_name[ INDETERMINADO ];
    
      switch(str[i])
      {
        case '+':
          printf("  %s,\n", resposta1);
          break;
        
        case '-':
          printf("  %s,\n", resposta2);
          break;
        
        case '*':
          printf("  %s,\n", resposta3);
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

void lexer(void)
{

  printf("TOKENS: [\n\n");
  tokenizar(" + -%*/ ()/* ");
  printf("\n]");

}

/* REFERENCIAS

//https://stackoverflow.com/questions/9907160/how-to-convert-enum-names-to-string-in-c
//https://www.geeksforgeeks.org/c-program-to-extract-characters-from-a-string/

*/