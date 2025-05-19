bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int i, j;
    char lini, lprox, lp;

    lini = word[0];
    if ( word[1] != \0 ) {
        lprox = word[1];
    }

    

    
}
/*
         (i-1,j)
 (i,j-1)  (i,j)  (i,j+1)
         (i+1,j)
*/ 

/*do{
        if ( word[j] != \0 && board[i][j] == word[j]) {
            do{
                if ( word[j] != \0 && board[i][j+1] == word[j] ) {
                
                    if ( board[i][j+2] == )
                }
            } while( j < boardColSize );
        }
        i++;        
    } while( i < boardSize );*/

    /*for ( i = 0; i < boardSize; i++ ) {
        
        for ( ; j < boardColSize; j++ ) {
            if ( board[i][j] == word[j]) {
                if ( board[i][j+1] == word[j+1] || board[i+1][j] == word[j+1] )
            }
        }
    }*/
