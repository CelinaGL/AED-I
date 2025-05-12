bool areOccurrencesEqual(char* s) {
    int i, t, dicionario[257], primeiro;
    t = strlen(s);

    for( i=0; i<t; i++ ){
       dicionario[s[i]]++;
    }

    primeiro = dicionario[s[0]];
    
    for ( i = 0; i < 257; i++ ) {
        if ( dicionario[i] != 0 && dicionario[i] != primeiro ){
            return false;
        }
    }
    return true;    
}