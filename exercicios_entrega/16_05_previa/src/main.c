bool testar ( char** board, int boardSize, int* boardColSize, char* word, int tamWord, int x, int y, int tamanho ) {
    char letra;
    if ( tamWord == tamanho ) {
        return true;
    }

    if ( x < 0 || y < 0 || x >= boardSize || y >= *boardColSize || 
        board[x][y] != word[tamanho] ) {
        return false;
    }

    letra = board[x][y];
    board[x][y] = '/';

    bool recursao;
    recursao =  ( 
    testar ( board, boardSize, boardColSize, word, tamWord, x - 1, y, tamanho + 1 ) ||
    testar ( board, boardSize, boardColSize, word, tamWord, x + 1, y, tamanho + 1 ) ||
    testar ( board, boardSize, boardColSize, word, tamWord, x, y - 1, tamanho + 1 ) ||
    testar ( board, boardSize, boardColSize, word, tamWord, x, y + 1, tamanho + 1 ) );

    board[x][y] = letra;
    return recursao;
}

bool exist( char** board, int boardSize, int* boardColSize, char* word ) {
    int tamWord, x, y;
    tamWord = strlen( word );
    
    for ( x = 0; x < boardSize; x++ ) {
        for ( y = 0; y < *boardColSize; y++ ) {
            if ( testar( board, boardSize, boardColSize, word, tamWord, x, y, 0 ) ) {
                return true;
            }
        }
    }
    return false;
}

/*
         (i,j-1)
 (i-1,j)  (i,j)  (i+1,j)
         (i,j+1)
*/ 