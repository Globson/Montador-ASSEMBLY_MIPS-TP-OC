#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]){
  FILE *f = NULL,*saida;
  char nome_arquivo[20],operacao[4],registrador1[4],registrador2[4],registrador3[4];
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
      printf("Operação ADD chamada!\n");
      fscanf(f," %c%c%c, %c%c%c, %c%c%c",&registrador1[0],&registrador1[1],&registrador1[2],&registrador2[0],&registrador2[1],&registrador2[2],&registrador3[0],&registrador3[1],&registrador3[2]);
      registrador1[3]='\0';
      registrador2[3]='\0';
      registrador3[3]='\0';
      printf("Registrador (%s)  (%s)  (%s)\n",registrador1,registrador2,registrador3);
    }
    else if(strcmp(operacao,"sub")==0){
      printf("Operação SUB chamada!\n");
      fscanf(f," %c%c%c, %c%c%c, %c%c%c",&registrador1[0],&registrador1[1],&registrador1[2],&registrador2[0],&registrador2[1],&registrador2[2],&registrador3[0],&registrador3[1],&registrador3[2]);
      registrador1[3]='\0';
      registrador2[3]='\0';
      registrador3[3]='\0';
      printf("Registrador (%s)  (%s)  (%s)\n",registrador1,registrador2,registrador3);
    }
    else if(strcmp(operacao,"and")==0){
      printf("Operação AND chamada!\n");
      fscanf(f," %c%c%c, %c%c%c, %c%c%c",&registrador1[0],&registrador1[1],&registrador1[2],&registrador2[0],&registrador2[1],&registrador2[2],&registrador3[0],&registrador3[1],&registrador3[2]);
      registrador1[3]='\0';
      registrador2[3]='\0';
      registrador3[3]='\0';
      printf("Registrador (%s)  (%s)  (%s)\n",registrador1,registrador2,registrador3);
    }
    else if(strcmp(operacao,"or")==0){
      printf("Operação OR chamada!\n");
      fscanf(f," %c%c%c, %c%c%c, %c%c%c",&registrador1[0],&registrador1[1],&registrador1[2],&registrador2[0],&registrador2[1],&registrador2[2],&registrador3[0],&registrador3[1],&registrador3[2]);
      registrador1[3]='\0';
      registrador2[3]='\0';
      registrador3[3]='\0';
      printf("Registrador (%s)  (%s)  (%s)\n",registrador1,registrador2,registrador3);
    }
    else if(strcmp(operacao,"nor")==0){
      printf("Operação NOR chamada!\n");
      fscanf(f," %c%c%c, %c%c%c, %c%c%c",&registrador1[0],&registrador1[1],&registrador1[2],&registrador2[0],&registrador2[1],&registrador2[2],&registrador3[0],&registrador3[1],&registrador3[2]);
      registrador1[3]='\0';
      registrador2[3]='\0';
      registrador3[3]='\0';
      printf("Registrador (%s)  (%s)  (%s)\n",registrador1,registrador2,registrador3);
    }
    else if(strcmp(operacao,"addi")==0){
      printf("Operação ADDI chamada!\n");
      fscanf(f," %c%c%c, %c%c%c, %d",&registrador1[0],&registrador1[1],&registrador1[2],&registrador2[0],&registrador2[1],&registrador2[2],&valor);
      registrador1[3]='\0';
      registrador2[3]='\0';
      printf("Registrador (%s)  (%s)  Valor (%d)\n",registrador1,registrador2,valor);
    }
    else if(strcmp(operacao,"andi")==0){
      printf("Operação ANDI chamada!\n");
      fscanf(f," %c%c%c, %c%c%c, %d",&registrador1[0],&registrador1[1],&registrador1[2],&registrador2[0],&registrador2[1],&registrador2[2],&valor);
      registrador1[3]='\0';
      registrador2[3]='\0';
      printf("Registrador (%s)  (%s)  Valor (%d)\n",registrador1,registrador2,valor);
    }
    else if(strcmp(operacao,"ori")==0){
      printf("Operação ORI chamada!\n");
    }
    else if(strcmp(operacao,"sll")==0){
      printf("Operação SLL chamada!\n");
      fscanf(f," %c%c%c, %c%c%c, %d",&registrador1[0],&registrador1[1],&registrador1[2],&registrador2[0],&registrador2[1],&registrador2[2],&valor);
      registrador1[3]='\0';
      registrador2[3]='\0';
      printf("Registrador (%s)  (%s)  Valor (%d)\n",registrador1,registrador2,valor);
    }
    else if(strcmp(operacao,"srl")==0){
      printf("Operação SRL chamada!\n");
      fscanf(f," %c%c%c, %c%c%c, %d",&registrador1[0],&registrador1[1],&registrador1[2],&registrador2[0],&registrador2[1],&registrador2[2],&valor);
      registrador1[3]='\0';
      registrador2[3]='\0';
      printf("Registrador (%s)  (%s)  Valor (%d)\n",registrador1,registrador2,valor);
    }
  }
  return 0;
}
