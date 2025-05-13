int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int i, j, r[100], mais = 0;

    for ( i = 0; i<accountsSize; i++ )  {
        r[i] = 0;
        for (j = 0; j<accountsColSize[i]; j++ ){
            r[i] = r[i] + accounts[i][j];
        }
         if ( r[i] != 0 && r[i] >= mais ) {
                mais = r[i];}
    }

    return mais;
}