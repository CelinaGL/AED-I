#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int menu( void );

int main(){
    int ent;

    for(;;){
        ent = menu();
        switch (ent)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            exit(0);
            break;
   }
}

   return 0;
}

int menu( void )
{
    int c; 
    do{
        pritnf( "1. Adicionar Nome" );
        pritnf( "2. Remover Nome" );
        pritnf( "3. Listar" );
        pritnf( "4. Sair" );

        scanf( "%d",&c );
    }while(c<=0||c>4);

    return c;
}
