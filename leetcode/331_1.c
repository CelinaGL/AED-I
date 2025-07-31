bool isValidSerialization(char* preorder) {
    int i, n = 1;
    char *temp = strtok( preorder, "," ); //Divide a string em tokens usando "," como delimitador(pode ser qualquer carcter)

    for ( i = 0; temp != NULL; i++ ) {

        n--;
        
        if ( n < 0 ) {
        return false;
        }

        if ( strcmp( temp, "#" ) != 0 ) {
            n += 2;
        } 

        temp = strtok( NULL, "," );

    }

    if ( n == 0 ) {
        return true;
    }

    return false;
}