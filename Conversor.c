#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Conversor.h"
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
char* Or_Bits_finais(int i){
  int k=0,j,x;
  char Palavra[16] = "000000000000000",aux[16];
  char* aux2 = Palavra;
  strcpy(aux,dec2bin(i));
  //printf("%s\n",aux );
  x=strlen(dec2bin(i));
  for(j=16-x;j<16;j++){
    Palavra[j] = aux[k];
    k++;
  }
  Palavra[16]='\0';
  //printf("%s\n",Palavra);
  return aux2;
}

char* Somador_binario(char* num1,char* num2){
  char soma[16], erro;
  char* aux = soma;
  int tam1, tam2, vai_um, i, j, x;
  do {
    erro = 'N';
    for (i=0; num1[i]!='\0'; i++)
      if ((num1[i] != '0') && (num1[i] != '1'))
        erro = 'S';
  } while (erro == 'S');
  do {
    erro = 'N';
    for (i=0; num2[i]!='\0'; i++)
      if ((num2[i] != '0') && (num2[i] != '1'))
        erro = 'S';
  } while (erro == 'S');
  /* Alinha números */
  tam1 = strlen(num1);
  tam2 = strlen(num2);
  while (tam1 > tam2) {
    for (j=tam2; j>=0; j--)
      num2[j+1] = num2[j];
  num2[0] = '0';
  tam2++;
  }
  while (tam1 < tam2) {
    for (j=tam1; j>=0; j--)
      num1[j+1] = num1[j];
  tam1++;
  }
  vai_um = 0;
  for (i=tam1-1; i>=0; i--) {
    x = vai_um + (num1[i] - '0') + (num2[i] - '0');
  if (x > 1)
    vai_um = 1;
  else
    vai_um = 0;
  //soma[i+1] = (x % 2) + '0';
  soma[i] = (x % 2) + '0';
  }
  //soma[0] = vai_um + '0';
  //soma[tam1+1] = '\0';
  soma[tam1] = '\0';
  printf("\n %s\n +\n %s\n =\n %s\n", num1, num2, soma);
  return aux;
}


char* Complemento2(char *Num){
  int x=strlen(Num),j;
  char um[2]="1",soma[16];
  char* aux = soma;
  printf(" Antes da negação: %s\n",Num);
  for(j=0;j<x;j++){
    if(Num[j]=='0'){
    Num[j]='1';}
    else{
      Num[j]='0';}
  }
  printf("Depois da negação: %s\n",Num);
  printf("Soma:\n");
  strcpy(soma,Somador_binario(Num,um));
  return aux;
}
