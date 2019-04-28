#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Conversores.h"

int main(int argc, char const *argv[]){
  FILE *f = NULL,*saida; //Ponteiros para arquivos de leitura e escrita.//
  char nome_arquivo[20],operacao[5],registrador1[5],registrador2[5],registrador3[5]; //Variaveis para fscanfs.//
  int valor; //Variavel para fscanf.//
  while(f == NULL){
    printf("\nDigite o nome do arquivo que deseja abrir:");
    scanf("%s",nome_arquivo);
    f = fopen(nome_arquivo,"r");
    //f= fopen("entrada.asm","r");  //Retornar comandos acima comentados antes de entregar.
  if(f == NULL){
    printf("\n\tErro!Nao foi possivel abrir arquivo!\n");}
  } //Saida do while apenas quando arquivo de entrada for aberto com sucesso.//
  saida = fopen("saida.txt","w"); //Abertura de arquivo de escrita.//
  printf("\n\tArquivo aberto com sucesso!\n");
  while(!feof(f)){
    fscanf(f,"%s",operacao); //Leitura do tipo de instrução.// Cada if a seguir descreve uma verificação quanto ao nome da operação de instrução.//
    if(strcmp(operacao,"add")==0){
      fprintf(saida, "000000"); //Escrita em arquivo inicial da instrução corresponte.//
      printf("Operação ADD chamada!\n");
      fscanf(f," %s %s %s",registrador1,registrador2,registrador3); //Leitura dos registradores.//
      registrador1[3]='\0'; //Definindo apenas 3 primeiras posições como relevantes em cada string que armazena um registrador.//
      registrador2[3]='\0';
      registrador3[3]='\0';
      Fprintf_registrador(registrador2,saida); //Escrevendo em arquivos de saida linguagens de maquina correspondentes aos registradores.//
      Fprintf_registrador(registrador3,saida);
      Fprintf_registrador(registrador1,saida);
      fprintf(saida, "00000100000\n"); //Escrita em arquivo final da instrução corresponte.//
      printf("Registradores: (%s)  (%s)  (%s)\n",registrador1,registrador2,registrador3); //
      strcpy(operacao,"Rst"); //Resetando variavel de operacao.//
    } //Processos semelhantes em leituras de outras instruções se repetem a seguir:
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
      strcpy(operacao,"Rst");
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
      strcpy(operacao,"Rst");
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
      strcpy(operacao,"Rst");
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
      strcpy(operacao,"Rst");
    }
    else if(strcmp(operacao,"addi")==0){
      char aux[16]; //Variavel auxiliar para print.//
      printf("Operação ADDI chamada!\n");
      fprintf(saida, "001000"); //Escrita inicial em arquivo corresponte a instrução reespectiva.//
      fscanf(f," %s %s %d",registrador1,registrador2,&valor); //Leitura de registradores e valores.//
      registrador1[3]='\0';
      registrador2[3]='\0';
      if(valor<0){ //Caso o numero passado seja negativo, a funções que transforma em complemento de 2 é chamada.//
        valor=valor*(-1); //Numero negativo é transformado em positivo para funcionamento correto de funcao Or_Bits_finais.//
        strcpy(aux,Or_Bits_finais(valor)); //Valor em binario é obtido.//
        strcpy(aux,Complemento2(aux)); //Valor em binario negativo é obtido.//
        valor=valor*(-1); //Convertendo numero em negativo novamente.//
      }
      else{ //Caso contraro, apenas é convertido em um numero binario de 16 bits.//
        strcpy(aux,Or_Bits_finais(valor));
      }
      Fprintf_registrador(registrador2,saida);//Escrita de codigos em linguagem de maquina correspontes aos registradores lidos.//
      Fprintf_registrador(registrador1,saida);
      fprintf(saida,"%s\n",aux); //Escrita final em arquivo valor de palavra de 16 bits obetida atravez da conversao do numero lido na entrada.//
      printf("Registradores: (%s)  (%s)  Valor: (%d)\n",registrador1,registrador2,valor);
      strcpy(operacao,"Rst"); //Resetando variavel de operacao.//
    }//Processos semelhantes em leituras de outras instruções se repetem a seguir:
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
      strcpy(operacao,"Rst");
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
      strcpy(operacao,"Rst");
    }
    else if(strcmp(operacao,"sll")==0){
      char aux[16]; //Variavel auxiliar de print.//
      printf("Operação SLL chamada!\n");
      fprintf(saida, "00000000000");//Escrita inicial da operação corresponte.//
      fscanf(f," %s %s %d",registrador1,registrador2,&valor); //Lendo registradores.//
      registrador1[3]='\0'; //Definindo as 3 primeiras posições de variavel registrador como relevantes.//
      registrador2[3]='\0';
      Fprintf_registrador(registrador2,saida); //Escrevendo em arquivo linguagem de maquina correspondente ao registrador lido.//
      Fprintf_registrador(registrador1,saida);
      strcpy(aux,Or_Bits_SLL_SRL(valor));  //Copiando palavra de 5 bits com valor em binario correspondente ao valor lido.//
      fprintf(saida,"%s",aux); //Escrita de palavra de 5 bits
      fprintf(saida, "000000\n"); //Escrita final da operação de SLL.//
      printf("Registradores: (%s)  (%s)  Valor: (%d)\n",registrador1,registrador2,valor);
      strcpy(operacao,"Rst"); //Resetando variavel operação.//
    }
    else if(strcmp(operacao,"srl")==0){
      char aux[16];//Variavel auxiliar de print.//
      printf("Operação SRL chamada!\n");
      fprintf(saida, "00000000000");//Escrita inicial da operação corresponte.//
      fscanf(f," %s %s %d",registrador1,registrador2,&valor); //Lendo registradores.//
      registrador1[3]='\0';
      registrador2[3]='\0';
      Fprintf_registrador(registrador2,saida);//Escrevendo em arquivo linguagem de maquina correspondente ao registrador lido.//
      Fprintf_registrador(registrador1,saida);
      strcpy(aux,Or_Bits_SLL_SRL(valor));//Copiando palavra de 5 bits com valor em binario correspondente ao valor lido./
      fprintf(saida,"%s",aux); //Escrita de palavra de 5 bits
      fprintf(saida, "000010\n");//Escrita final da operação de SRl.//
      printf("Registradores (%s)  (%s)  Valor: (%d)\n",registrador1,registrador2,valor);
      strcpy(operacao,"Rst"); //Resetando variavel operação.//
    }
    //Funçoes a seguir sao de pontuação extra:
    else if(strcmp(operacao,"sw")==0){
      printf("Operação SW chamada!\n");
      char aux[16];
      fprintf(saida, "101011");// Escrita inicial da instrução .//
      fscanf(f," %s %d[^(]%s",registrador1,&valor,registrador2);//Leitura de registradores.//
      registrador1[3]='\0';
      registrador2[3]='\0';
      Fprintf_registrador(registrador2,saida);//Escrita em binario de registradores
      Fprintf_registrador(registrador1,saida);
      strcpy(aux,Or_Bits_finais(valor));//Conversao do valor para binario.//
      fprintf(saida,"%s\n",aux);//Escrita do valor em binario.//
      printf("Registradores (%s)  (%s)  Valor: (%d)\n",registrador1,registrador2,valor);
      strcpy(operacao,"Rst");
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
      strcpy(operacao,"Rst");
    }
    else if(strcmp(operacao,"move")==0){
      fprintf(saida, "000000");
      printf("Operação MOVE chamada!\n");
      fscanf(f," %s %s",registrador1,registrador2);
      registrador1[3]='\0';
      registrador2[3]='\0';
      strcpy(registrador3,"$ze"); //Função identica a instrução add porem se o registrador $zero.//
      registrador3[3]='\0';
      Fprintf_registrador(registrador2,saida);
      Fprintf_registrador(registrador3,saida);
      Fprintf_registrador(registrador1,saida);
      fprintf(saida, "00000100000\n");
      printf("Registradores: (%s)  (%s)\n",registrador1,registrador2);
      strcpy(operacao,"Rst");
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
      strcpy(operacao,"Rst");
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
      strcpy(operacao,"Rst");
    }
  }
  fclose(f);//Fechamento de arquivos.//
  fclose(saida);
  printf("\n\t-->Arquivo de saida('saida.txt') gerado com sucesso!<--\n");
  return 0;
}
