#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Conversor.h"

int main(int argc, char const *argv[]){
  FILE *f = NULL,*saida;
  char nome_arquivo[20],operacao[4],registrador1[5],registrador2[5],registrador3[5],binario[16];
  int valor;
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
    if(strcmp(operacao,"add")==0){
      fprintf(saida, "000000");
      printf("Operação ADD chamada!\n");
      fscanf(f," %s %s %s",registrador1,registrador2,registrador3);
      registrador1[3]='\0';
      registrador2[3]='\0';
      registrador3[3]='\0';
      if(strcmp(registrador1,"$s0")==0){
        //fazer escrita para o reespectivo registrador.//
      }
      else if(strcmp(registrador1,"$s1")==0){
        //fazer escrita para o reespectivo registrador.//
      }
      else if(strcmp(registrador1,"$s2")==0){
        //fazer escrita para o reespectivo registrador.//
      }
      else if(strcmp(registrador1,"$s3")==0){
        //fazer escrita para o reespectivo registrador.//
      }
      else if(strcmp(registrador1,"$s4")==0){
        //fazer escrita para o reespectivo registrador.//
      }
      else if(strcmp(registrador1,"$s5")==0){
        //fazer escrita para o reespectivo registrador.//
      }
      else if(strcmp(registrador1,"$s6")==0){
        //fazer escrita para o reespectivo registrador.//
      }
      else if(strcmp(registrador1,"$s7")==0){
        //fazer escrita para o reespectivo registrador.//
      }
      fprintf(saida, "00000100000\n");
      printf("Registrador (%s)  (%s)  (%s)\n",registrador1,registrador2,registrador3);
    }
    else if(strcmp(operacao,"sub")==0){
      printf("Operação SUB chamada!\n");
      fprintf(saida, "000000");
      fscanf(f," %s %s %s",registrador1,registrador2,registrador3);
      registrador1[3]='\0';
      registrador2[3]='\0';
      registrador3[3]='\0';
      fprintf(saida, "00000100010\n");
      printf("Registrador (%s)  (%s)  (%s)\n",registrador1,registrador2,registrador3);
    }
    else if(strcmp(operacao,"and")==0){
      printf("Operação AND chamada!\n");
      fprintf(saida, "000000");
      fscanf(f," %s %s %s",registrador1,registrador2,registrador3);
      registrador1[3]='\0';
      registrador2[3]='\0';
      registrador3[3]='\0';
      fprintf(saida, "00000100100\n");
      printf("Registrador (%s)  (%s)  (%s)\n",registrador1,registrador2,registrador3);
    }
    else if(strcmp(operacao,"or")==0){
      printf("Operação OR chamada!\n");
      fprintf(saida, "000000");
      fscanf(f," %s %s %s",registrador1,registrador2,registrador3);
      registrador1[3]='\0';
      registrador2[3]='\0';
      registrador3[3]='\0';
      fprintf(saida, "00000100101\n");
      printf("Registrador (%s)  (%s)  (%s)\n",registrador1,registrador2,registrador3);
    }
    else if(strcmp(operacao,"nor")==0){
      printf("Operação NOR chamada!\n");
      fprintf(saida, "000000");
      fscanf(f," %s %s %s",registrador1,registrador2,registrador3);
      registrador1[3]='\0';
      registrador2[3]='\0';
      registrador3[3]='\0';
      fprintf(saida, "00000100111\n");
      printf("Registrador (%s)  (%s)  (%s)\n",registrador1,registrador2,registrador3);
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
      fprintf(saida,"%s\n",aux);
      printf("Registrador (%s)  (%s)  Valor (%d)\n",registrador1,registrador2,valor);
    }
    else if(strcmp(operacao,"andi")==0){
      printf("Operação ANDI chamada!\n");
      fprintf(saida, "001100");
      fscanf(f," %s %s %d",registrador1,registrador2,&valor);
      registrador1[3]='\0';
      registrador2[3]='\0';
      printf("Registrador (%s)  (%s)  Valor (%d)\n",registrador1,registrador2,valor);
    }
    else if(strcmp(operacao,"ori")==0){
      printf("Operação ORI chamada!\n");
      fprintf(saida, "001101");
      fscanf(f," %s %s %d",registrador1,registrador2,&valor);
      registrador1[3]='\0';
      registrador2[3]='\0';
      printf("Registrador (%s)  (%s)  Valor (%d)\n",registrador1,registrador2,valor);
    }
    else if(strcmp(operacao,"sll")==0){
      char aux[16];
      printf("Operação SLL chamada!\n");
      fprintf(saida, "000000");
      fscanf(f," %s %s %d",registrador1,registrador2,&valor);
      registrador1[3]='\0';
      registrador2[3]='\0';
      strcpy(aux,Or_Bits_finais(valor));
      fprintf(saida,"%s\n",aux);
      printf("Registrador (%s)  (%s)  Valor (%d)\n",registrador1,registrador2,valor);
    }
    else if(strcmp(operacao,"srl")==0){
      char aux[16];
      printf("Operação SRL chamada!\n");
      fprintf(saida, "000000");
      fscanf(f," %s %s %d",registrador1,registrador2,&valor);
      registrador1[3]='\0';
      registrador2[3]='\0';
      strcpy(aux,Or_Bits_finais(valor));
      fprintf(saida,"%s\n",aux);
      printf("Registrador (%s)  (%s)  Valor (%d)\n",registrador1,registrador2,valor);
    }
  }
  fclose(f);
  fclose(saida);
  return 0;
}
