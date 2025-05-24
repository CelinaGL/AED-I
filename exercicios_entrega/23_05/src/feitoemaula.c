char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {
    int i, letras[27], p[27], qP, qE;
    char *palavra;
    bool e[27];  

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
    for ( i = 0; i < 27; i++) {
        if ( letras[i] != 0 ) {
        qP++;
        }
    }
    

    while ( *words != '\0' ) {
        while ( **words != '\0' ) {
            p[**words - 'a']++;
            (*words)++;

        }
        for ( i = 0; i < 27; i++) {
            if ( letras[i] == p[i] ) {
             e[i] = true;
             qE++;
            }
        }

        if ( qP == qE) {
            break;
        }

        words++;
    }
    return (**words); 
}
