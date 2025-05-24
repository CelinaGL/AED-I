char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int i, j = 0, k, letras[27] = {0}, valido;
    char *palavra = NULL; 
    bool e;

    while ( *licensePlate != '\0' ) {
        if ( ( *licensePlate >= 'a' && *licensePlate <= 'z' ) || 
        ( *licensePlate >= 'A' && *licensePlate <= 'Z' ) ) {

            if ( *licensePlate >= 'a' && *licensePlate <= 'z' ) {
                letras[*licensePlate - 'a']++;
            }

             if ( *licensePlate >= 'A' && *licensePlate <= 'Z' ) {
                letras[*licensePlate - 'A']++;
            }
        }
        licensePlate++;
    }
    
    for ( i = 0; i < wordsSize; i++ ) {
        int p[27] = {0};
        j = 0;

        while ( words[i][j] != '\0' ) {
            p[words[i][j] - 'a']++;
            j++;
        }

        e = true;

        for ( k = 0; k < 27; k++) {
            if ( letras[k] > p[k] ) {
                e = false;
                break;
            }
        }
        if ( e == true && ( palavra == NULL || strlen(words[i]) < strlen(palavra) ) ) {
                    palavra = words[i];
        }
    }
    return palavra;
}
