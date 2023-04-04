#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define OPERACOES C(MAIS)C(MENOS)C(MULTIPLICACAO)C(DIVIDIR)C(INDETERMINADO)C(POTENCIA)C(N_INTEIRO)C(N_REAL)
#define C(x) x,
enum color { OPERACOES TOP };
#undef C

#define C(x) #x,    
const char * const op[] = { OPERACOES };

int converterCaractere(char letra)
{
  switch (letra) 
  {
    case '0': 
      return 0; 
      break;
    
    case '1': 
      return 1; 
      break;
    
    case '2': 
      return 2; 
      break;
    
    case '3': 
      return 3; 
      break;
    
    case '4': 
      return 4; 
      break;
    
    case '5': 
      return 5; 
      break;
    
    case '6': 
      return 6; 
      break;
    
    case '7': 
      return 7; 
      break;
    
    case '8': 
      return 8; 
      break;
    
    case '9': 
      return 9; 
      break;
    
   default:
      break;
  }
  
}

void SomaInteiro(int num1, int num2)
{  
    // int tamanho = 0;
    // tamanho = sizeof(vetor) / sizeof(int);

    // printf("So, array length is: %d\n", tamanho);
  
    // for (int i = 0; i < tamanho; i++)
    // {
    //   printf("Valor da soma: %d\n", vetor[i]);
    // }
    printf("%d + %d = ", num1, num2);
    int result = num1 + num2;
    printf("%d", result);
  
}


void SomaReal(double num1, double num2)
{  
    // int tamanho = 0;
    // tamanho = sizeof(vetor) / sizeof(int);

    // printf("So, array length is: %d\n", tamanho);
  
    // for (int i = 0; i < tamanho; i++)
    // {
    //   printf("Valor da soma: %d\n", vetor[i]);
    // }
    printf("%lf + %lf = ", num1, num2);
    double result = num1 + num2;
    printf("%lf", result);
  
}
// void Subtracao()
// {
  
// }
// void Multiplicacao()
// {
  
// }
// void Divisao()
// {
  
// }

void tokenizar(char *str)
{
    const char *resposta1 = op[ MAIS ];
    const char *resposta2 = op[ MENOS ];
    const char *resposta3 = op[ MULTIPLICACAO ];
    const char *resposta4 = op[ DIVIDIR ];
    const char *resposta5 = op[ INDETERMINADO ];
    const char *resposta6 = op[ POTENCIA ];
    const char *resposta7 = op[ N_INTEIRO ];
    const char *resposta8 = op[ N_REAL ];
    int achouPonto = 0;
    int resultado, resultado2; 
    int acumulador[100] = {};
    int contador = 0; 
    int j = 0; 
    bool soma = false;
  
    for (int i = 0; i <= strlen(str); i++) 
    {
    
      switch(str[i])
      {
        
        case '+':
         // printf(" + "); // imprime MAIS
          soma = true;
          break;
        
        case '-':
          printf("  %s,\n", resposta2); // imprime MENOS
          break;
        
        case '*':
      
          if(str[i] == str[i + 1])  printf("  %s,\n", resposta6); // se caractere proximo for igual ao atual, entao imprime POTENCIA
          if(str[i] != str[i + 1])  printf("  %s,\n", resposta3); // se caractere proximo for diferente do caractere atual imprime MULTIPLICACAO
          if(str[i + 1] == ' ' || str[i + 1] == '*') i = i + 1; // avanca um caractere para nao haver impressao repetida
          
          break;
          
        case '/':
          printf("  %s,\n", resposta4); // imprime DIVIDIR
          break;

        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.': 
       
         // while (str[i] != ' ') 
          //{
            //printf("c => %c\n", str[i]);
            resultado2 = resultado;
            resultado = converterCaractere(str[i]);
            contador = contador + 1;

            if(contador == 2) SomaInteiro(resultado2, resultado);
        
            //if(str[i] == ' ') //achouPonto = achouPonto + 1; // se houver encontrado o caractere ponto, contabiliza a variavel achouPonto
              //printf("c => %c\n", str[i + 2]);
              //printf("c => %c\n", str[i + 2]);
              //resultado = converterCaractere(str[i]);
  
              //resultado2 = converterCaractere(str[i + 1]);

              //printf("caractere %d\n", resultado);
              //printf("caractere2 %d\n", resultado2);
  
              //Soma(resultado, resultado2);
  
            //acumulador[j] = resultado; /// acumula valores de caracteres na sequencia
            
            //if (acumulador[j] > 0) printf("Acumulador %d\n", acumulador[j]);
            //if(resultado > 0) printf("resultado %d\n", resultado);
            //printf(soma ? "true\n" : "false\n");
            //printf("num 1 %d\n", acumulador[j]);
            //printf("num 2 %d\n", acumulador[j + 2]);
            
            //i = i + 2; // avanca um caractere para nao haver contabilização de caractere repetido
            //j = j + 1;
   
         // }

          //printf("Acumulador")

          //j = 0;
         
          //printf("num 1 %d\n", acumulador[j]);
          //printf("num 2 %d\n", acumulador[j + 2]);
        
          
          //if(achouPonto == 0 && soma == true) Soma(acumulador[j], acumulador[j + 2]);
            //printf("  %s,\n", resposta7); //Soma(acumulador); // imprime N_INTEIRO pois nao achou ponto
          //if(achouPonto == 1) printf("  %s,\n", resposta8); // imprime N_REAL pois achou apenas 1 ponto
          //if(achouPonto > 1) printf("  %s,\n", resposta5); // imprime INDETERMINADO pois achou mais de 1 ponto

          //achouPonto = 0; // zera variavel para contabilizar numeros reais novamente
          
          break;
        
        case ' ':
          break; // pula impressão de caractere espaço
        
        default:
          printf("  %s,\n", resposta5); // imprime INDETERMINADO
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
  fp = fopen("entrada.txt", "r"); // abre arquivo entrada.txt
  if (fp == NULL) // valida se arquivo esta em branco
    exit(EXIT_FAILURE);
  
  while ((read = getline(&line, &len, fp)) != -1) 
  { // enquanto a linha do entrada.txt estiver preenchida
   
    printf("TOKENS: [\n\n");
    tokenizar(line); // chama funcao tokenizar pra compilar palavra de entrada.txt
    printf("\n]");
      
  }

  fclose(fp); // fecha arquivo entrada.txt
  
  if (line) // verifica cada linha preenchida
    free(line); // libera memoria
  exit(EXIT_SUCCESS); // sai do programa

}

/* REFERENCIAS

https://stackoverflow.com/questions/9907160/how-to-convert-enum-names-to-string-in-c
https://www.geeksforgeeks.org/c-program-to-extract-characters-from-a-string/
https://stackoverflow.com/questions/10349842/how-does-c-know-the-end-of-my-string

*/