#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static char data[] = {42, 0, 0, 32, 128, 48, 129, 16, 130, 240};
static int data2[] = {42, 0, 0, 32, 128, 48, 129, 16, 130, 240};
static double Soma(double a, double b) {return a + b;}

void generateBinaryFile(const char* filename, const char* data, size_t size) {
    FILE* file = fopen(filename, "wb");  

    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    fwrite(data, sizeof(char), size, file); 

    fclose(file);
}

void readBinaryFile(const char* filename, const char* data, size_t size) {
    int acumulador, registrador, saida, lda, add = 0;
    int v1 = 10;
    int v2 = 5;
    bool N = false;
    bool Z = true;
  
    FILE* file = fopen(filename, "wb");

    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    fread(data, sizeof(char), size, file);  
  
    for (int i = 0; i < size; i++) { 
      if (data[i] < 0){
       
        saida = data2[i];
      }
      else{ 
        saida = data[i];
      }

      switch(saida){
        case 16:
          printf("\n          4           |     %d       |    STA 130          \n",saida);
          printf("\n          5           |     130      |               \n");
          printf("\n          6           |     240      |    HLT         \n");
          printf("\n===========================================================\n");
          printf("\n\n");

          printf("DADOS: \n");
          printf("\n==========================================\n");
          printf("\n        Endereço      |    Dado            \n");
          printf("\n          128         |     %d          \n",v1);
          printf("\n          129         |     %d          \n",v2);
          printf("\n          130         |     %d          \n",acumulador);
          printf("\n==========================================\n");
          printf("\n\n");
          printf("\nNEANDER: \n");
          printf("\n==========================================\n");
          printf("\n");
          printf("             Acumulador = %d\n"       , acumulador);    
          break;
        case 32:
          lda = v1;
          printf("\n\nPROGRAMA: \n");
          printf("\n===========================================================\n");
          printf("\n        Endereço      |    Dado      |   Mnemônico          \n");
          printf("\n          0           |     %d       |    LDA 128           \n",saida);
          printf("\n          1           |     128      |               \n");
      
          break;
        case 48:
          add = v2;
          printf("\n          2           |     %d       |    ADD 129           \n",saida);
          printf("\n          3           |     129      |               \n");
          acumulador = Soma(lda, add);
          registrador = i + 1;
          break;
        // case 64:
        //   break;
        // case 80;
        //   break;
        // case 96:
        //   break;
        // case 128:
        //   break;
        // case 144:
        //   break;
        // case 160:
        //   break;
        case 240:
          if (acumulador > 0) Z = false;
          registrador = registrador + 1; //adiciona + 1 posicao devido ao valor 240 HLT
          printf("             Registrador = %d\n"       , registrador);
          printf("             N = %s\n"        ,N ? "true" : "false");
          printf("             Z = %s\n"        ,Z ? "true" : "false");
          printf("\n==========================================\n");
          break;

        default:
          printf("");
      }
    }

    fclose(file); 
}


int main() {

    size_t size = sizeof(data) / sizeof(data[0]); 
  
    generateBinaryFile("nre teste.nar", data, size);  

    readBinaryFile("nre teste.nar", data, size);  

    return 0;
}
