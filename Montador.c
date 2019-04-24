#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Conversores.h"

int main(int argc, char const *argv[]){
  FILE *f = NULL,*saida;
  char nome_arquivo[20],*operacao,registrador1[5],registrador2[5],registrador3[5];
  int valor;
  operacao = (char*)malloc(sizeof(char));
  while(f == NULL){
    printf("\nDigite o nome do arquivo que deseja abrir:");
    //scanf("%s",nome_arquivo);
    //f = fopen(nome_arquivo,"r");
    f= fopen("entrada.asm","r");  //Retornar comandos acima comentados antes de entregar.
  if(f == NULL){
    printf("\n\tErro!Nao foi possivel abrir arquivo!\n");}
  }
  saida = fopen("saida.txt","w");
  printf("\n\tArquivo aberto com sucesso!\n");
  while(!feof(f)){
    fscanf(f,"%s",operacao);
    //operacao[3]='\0';
    if(strcmp(operacao,"add")==0){
      fprintf(saida, "000000");
      printf("Operação ADD chamada!\n");
      fscanf(f," %s %s %s",registrador1,registrador2,registrador3);
      registrador1[3]='\0';
      registrador2[3]='\0';
      registrador3[3]='\0';
      Fprintf_registrador(registrador2,saida);
      Fprintf_registrador(registrador3,saida);
      Fprintf_registrador(registrador1,saida);
      fprintf(saida, "00000100000\n");
      printf("Registradores: (%s)  (%s)  (%s)\n",registrador1,registrador2,registrador3);
      operacao = (char*)malloc(sizeof(char));
    }
    else if(strcmp(operacao,"sub")==0){
      printf("Operação SUB chamada!\n");
      fprintf(saida, "000000");
      fscanf(f," %s %s %s",registrador1,registrador2,registrador3);
      registrador1[3]='\0';
      registrador2[3]='\0';
      registrador3[3]='\0';
      Fprintf_registrador(registrador2,saida);
      Fprintf_registrador(registrador3,saida);
      Fprintf_registrador(registrador1,saida);
      fprintf(saida, "00000100010\n");
      printf("Registradores: (%s)  (%s)  (%s)\n",registrador1,registrador2,registrador3);
      operacao = (char*)malloc(sizeof(char));
    }
    else if(strcmp(operacao,"and")==0){
      printf("Operação AND chamada!\n");
      fprintf(saida, "000000");
      fscanf(f," %s %s %s",registrador1,registrador2,registrador3);
      registrador1[3]='\0';
      registrador2[3]='\0';
      registrador3[3]='\0';
      Fprintf_registrador(registrador2,saida);
      Fprintf_registrador(registrador3,saida);
      Fprintf_registrador(registrador1,saida);
      fprintf(saida, "00000100100\n");
      printf("Registradores: (%s)  (%s)  (%s)\n",registrador1,registrador2,registrador3);
      operacao = (char*)malloc(sizeof(char));
    }
    else if(strcmp(operacao,"or")==0){
      printf("Operação OR chamada!\n");
      fprintf(saida, "000000");
      fscanf(f," %s %s %s",registrador1,registrador2,registrador3);
      registrador1[3]='\0';
      registrador2[3]='\0';
      registrador3[3]='\0';
      Fprintf_registrador(registrador2,saida);
      Fprintf_registrador(registrador3,saida);
      Fprintf_registrador(registrador1,saida);
      fprintf(saida, "00000100101\n");
      printf("Registradores: (%s)  (%s)  (%s)\n",registrador1,registrador2,registrador3);
      operacao = (char*)malloc(sizeof(char));
    }
    else if(strcmp(operacao,"nor")==0){
      printf("Operação NOR chamada!\n");
      fprintf(saida, "000000");
      fscanf(f," %s %s %s",registrador1,registrador2,registrador3);
      registrador1[3]='\0';
      registrador2[3]='\0';
      registrador3[3]='\0';
      Fprintf_registrador(registrador2,saida);
      Fprintf_registrador(registrador3,saida);
      Fprintf_registrador(registrador1,saida);
      fprintf(saida, "00000100111\n");
      printf("Registradores: (%s)  (%s)  (%s)\n",registrador1,registrador2,registrador3);
      operacao = (char*)malloc(sizeof(char));
    }
    else if(strcmp(operacao,"addi")==0){
      char aux[16];
      printf("Operação ADDI chamada!\n");
      fprintf(saida, "001000");
      fscanf(f," %s %s %d",registrador1,registrador2,&valor);
      registrador1[3]='\0';
      registrador2[3]='\0';
      if(valor<0){
        valor=valor*(-1);
        strcpy(aux,Or_Bits_finais(valor));
        strcpy(aux,Complemento2(aux));
        valor=valor*(-1);
      }
      else{
        strcpy(aux,Or_Bits_finais(valor));
      }
      Fprintf_registrador(registrador2,saida);
      Fprintf_registrador(registrador1,saida);
      fprintf(saida,"%s\n",aux);
      printf("Registradores: (%s)  (%s)  Valor: (%d)\n",registrador1,registrador2,valor);
      operacao = (char*)malloc(sizeof(char));
    }
    else if(strcmp(operacao,"andi")==0){
      char aux[16];
      printf("Operação ANDI chamada!\n");
      fprintf(saida, "001100");
      fscanf(f," %s %s %d",registrador1,registrador2,&valor);
      registrador1[3]='\0';
      registrador2[3]='\0';
      if(valor<0){
        valor=valor*(-1);
        strcpy(aux,Or_Bits_finais(valor));
        strcpy(aux,Complemento2(aux));
        valor=valor*(-1);
      }
      else{
        strcpy(aux,Or_Bits_finais(valor));
      }
      Fprintf_registrador(registrador2,saida);
      Fprintf_registrador(registrador1,saida);
      fprintf(saida,"%s\n",aux);
      printf("Registradores: (%s)  (%s)  Valor: (%d)\n",registrador1,registrador2,valor);
      operacao = (char*)malloc(sizeof(char));
    }
    else if(strcmp(operacao,"ori")==0){

      char aux[16];
      printf("Operação ORI chamada!\n");
      fprintf(saida, "001101");
      fscanf(f," %s %s %d",registrador1,registrador2,&valor);
      registrador1[3]='\0';
      registrador2[3]='\0';
      if(valor<0){
        valor=valor*(-1);
        strcpy(aux,Or_Bits_finais(valor));
        strcpy(aux,Complemento2(aux));
        valor=valor*(-1);
      }
      else{
        strcpy(aux,Or_Bits_finais(valor));
      }
      Fprintf_registrador(registrador2,saida);
      Fprintf_registrador(registrador1,saida);
      fprintf(saida,"%s\n",aux);
      printf("Registradores: (%s)  (%s)  Valor: (%d)\n",registrador1,registrador2,valor);
      operacao = (char*)malloc(sizeof(char));
    }
    else if(strcmp(operacao,"sll")==0){
      char aux[16];
      printf("Operação SLL chamada!\n");
      fprintf(saida, "00000000000");
      fscanf(f," %s %s %d",registrador1,registrador2,&valor);
      registrador1[3]='\0';
      registrador2[3]='\0';
      Fprintf_registrador(registrador2,saida);
      Fprintf_registrador(registrador1,saida);
      strcpy(aux,Or_Bits_SLL_SRL(valor));
      fprintf(saida,"%s",aux);
      fprintf(saida, "000000\n");
      printf("Registradores: (%s)  (%s)  Valor: (%d)\n",registrador1,registrador2,valor);
      operacao = (char*)malloc(sizeof(char));
    }
    else if(strcmp(operacao,"srl")==0){
      char aux[16];
      printf("Operação SRL chamada!\n");
      fprintf(saida, "00000000000");
      fscanf(f," %s %s %d",registrador1,registrador2,&valor);
      registrador1[3]='\0';
      registrador2[3]='\0';
      Fprintf_registrador(registrador2,saida);
      Fprintf_registrador(registrador1,saida);
      strcpy(aux,Or_Bits_SLL_SRL(valor));
      fprintf(saida,"%s",aux);
      fprintf(saida, "000010\n");
      printf("Registradores (%s)  (%s)  Valor: (%d)\n",registrador1,registrador2,valor);
      operacao = (char*)malloc(sizeof(char));
    }
    else if(strcmp(operacao,"sw")==0){
      printf("Operação SW chamada!\n");
      char aux[16];
      fprintf(saida, "101011");
      fscanf(f," %s %d[^(]%s",registrador1,&valor,registrador2);
      registrador1[3]='\0';
      registrador2[3]='\0';
      Fprintf_registrador(registrador2,saida);
      Fprintf_registrador(registrador1,saida);
      strcpy(aux,Or_Bits_finais(valor));
      fprintf(saida,"%s\n",aux);
      printf("Registradores (%s)  (%s)  Valor: (%d)\n",registrador1,registrador2,valor);
      operacao = (char*)malloc(sizeof(char));
    }
    else if(strcmp(operacao,"lw")==0){
      printf("Operação LW chamada!\n");
      char aux[16];
      fprintf(saida, "100011");
      fscanf(f," %s %d[^(]%s",registrador1,&valor,registrador2);
      registrador1[3]='\0';
      registrador2[3]='\0';
      Fprintf_registrador(registrador2,saida);
      Fprintf_registrador(registrador1,saida);
      strcpy(aux,Or_Bits_finais(valor));
      fprintf(saida,"%s\n",aux);
      printf("Registradores (%s)  (%s)  Valor: (%d)\n",registrador1,registrador2,valor);
      operacao = (char*)malloc(sizeof(char));
    }
    else if(strcmp(operacao,"move")==0){
      fprintf(saida, "000000");
      printf("Operação MOVE chamada!\n");
      fscanf(f," %s %s",registrador1,registrador2);
      registrador1[3]='\0';
      registrador2[3]='\0';
      strcpy(registrador3,"$ze");
      registrador3[3]='\0';
      Fprintf_registrador(registrador2,saida);
      Fprintf_registrador(registrador3,saida);
      Fprintf_registrador(registrador1,saida);
      fprintf(saida, "00000100000\n");
      printf("Registradores: (%s)  (%s)\n",registrador1,registrador2);
      operacao = (char*)malloc(sizeof(char));
    }
    else if(strcmp(operacao,"bne")==0){
      char aux[16];
      fprintf(saida, "000101");
      printf("Operação BNE chamada!\n");
      fscanf(f," %s %s %d",registrador1,registrador2,&valor);
      registrador1[3]='\0';
      registrador2[3]='\0';
      if(valor<0){
        valor=valor*(-1);
        strcpy(aux,Or_Bits_finais(valor));
        strcpy(aux,Complemento2(aux));
        valor=valor*(-1);
      }
      else{
        strcpy(aux,Or_Bits_finais(valor));
      }
      Fprintf_registrador(registrador1,saida);
      Fprintf_registrador(registrador2,saida);
      fprintf(saida,"%s\n",aux);
      printf("Registradores: (%s)  (%s)  Valor: (%d)\n",registrador1,registrador2,valor);
      operacao = (char*)malloc(sizeof(char));
    }
    else if(strcmp(operacao,"beq")==0){
      char aux[16];
      fprintf(saida, "000100");
      printf("Operação BEQ chamada!\n");
      fscanf(f," %s %s %d",registrador1,registrador2,&valor);
      registrador1[3]='\0';
      registrador2[3]='\0';
      if(valor<0){
        valor=valor*(-1);
        strcpy(aux,Or_Bits_finais(valor));
        strcpy(aux,Complemento2(aux));
        valor=valor*(-1);
      }
      else{
        strcpy(aux,Or_Bits_finais(valor));
      }
      Fprintf_registrador(registrador1,saida);
      Fprintf_registrador(registrador2,saida);
      fprintf(saida,"%s\n",aux);
      printf("Registradores: (%s)  (%s)  Valor: (%d)\n",registrador1,registrador2,valor);
      operacao = (char*)malloc(sizeof(char));
    }
  }
  fclose(f);
  fclose(saida);
  printf("\n\t-->Arquivo de saida('saida.txt') gerado com sucesso!<--\n");
  return 0;
}
