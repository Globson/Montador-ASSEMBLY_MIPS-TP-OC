#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define swap( a, b )   do{ int tmp = a; a = b; b = tmp; }while(0)

char* dec2bin(int d){
    char bin[16];
    char *aux = bin;
    int i, j;

    for(i = 0; d > 0; d /= 2, i++ )
        bin[i] = (d % 2) ? '1' : '0';

    for( j = 0; j < (i / 2); j++ )
        swap( bin[j], bin[ i - j - 1 ] );

    bin[i] = '\0';

    return aux;
}
char* Or_final(int i){
  int k=0,j,x;
  char instrucao[16] = "000000000000000",aux[16];
  char* aux2 = instrucao;
  strcpy(aux,dec2bin(i));
  x=strlen(dec2bin(i));
  for(j=16-x;j<16;j++){
    instrucao[j] = aux[k];
    k++;
  }
  instrucao[16]='\0';
  //printf("%s\n", aux2);
  return aux2;
}
int main(){
    int i = 53;
    char aux3[16];
    strcpy(aux3,Or_final(i));
    printf("%s\n",aux3);

}
