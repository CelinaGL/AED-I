#include <stdio.h>

int main() {
    int x = 0;
    char palavra[100];

    printf ( "Digite uma palavra: " );
    scanf ( "%[^\n]s", palavra );
    
    do {
        x++;
    } while( palavra[x] != '\0' );

    printf ( "Quantidade de letras: %d", x );

    return 0;
}