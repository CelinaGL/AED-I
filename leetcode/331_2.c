bool isValidSerialization(char* preorder) {
    int n = 1;
    for ( int i = 0; preorder[i] != NULL; ) {
        
        if ( n == 0 ) {
            return false;
        }

        if ( preorder[i] == ',' ) {
            i++;
        }

        if ( preorder[i] == '#' ) {
            n--;
            i++;
        } else {
            while ( preorder[i] != NULL && preorder[i] != ',' ){  
                i++;
            }
            n++;  
        }

    }
      
    if ( n == 0 ) {
        return true;
    }

    return false;
}