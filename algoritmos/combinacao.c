#include <stdio.h>

int main() {
    int i, j, n = 10, comb[11][11];

    for ( i = 0; i <= n; i++ ) {
        comb[i][0] = 1; 
        comb[i][i] = 1;

        for ( j = 1; j < i; j++ ) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]);
        }
    }

    for ( i = 0; i <= n; i++ ) {
        for ( j = 0; j < i + 1; j++ ) {
           printf( "%d ", comb[i][j] );
        }
        printf( "\n" );
    }

    return 0;

}