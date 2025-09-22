#include <stdio.h>

void Insertionsort(int data[], int n);

int main() {
    int d[2], n = 2, k;
    d[0] = 1; d[1] = 0;

    Insertionsort( d, n );

    for ( k = 0; k < n; k++ ) {
        printf( "%d ", d[k] );
    }

    return 0;
}


void Insertionsort(int data[], int n) { 
    int tmp,i,j;
    for ( j = 1; j < n; j++ ) { 
        i = j - 1;
        tmp = data[j]; 
        while ( (i>=0) && (tmp < data[i]) ) { 
            data[i+1] = data[i];
            i--; 
        }//while
    data[i+1] = tmp; 
    }//for
}//Insertionsor