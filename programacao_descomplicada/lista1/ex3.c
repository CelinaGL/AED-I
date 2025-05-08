#include <stdio.h>

int main(){

    int a, b, c;

    printf( "Digite 3 numeros inteiros: " );
    scanf( "%d %d %d", &a, &b, &c );
    
    printf( "Resultado da soma: %d", a+b+c );

    return 0;
}