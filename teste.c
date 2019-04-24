#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define swap( a, b )   do{ int tmp = a; a = b; b = tmp; }while(0)

char* dec2bin(int d){
    char bin[20];
    char *aux = bin;
    int i, j;

    for(i = 0; d > 0; d /= 2, i++ )
        bin[i] = (d % 2) ? '1' : '0';

    for( j = 0; j < (i / 2); j++ )
        swap( bin[j], bin[ i - j - 1 ] );

    bin[i] = '\0';

    return aux;
}

int main(){
    int i = 53;
    printf("%s", dec2bin(i));
}