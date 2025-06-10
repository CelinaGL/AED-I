#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu( void *pBuffer );
void add( void *pBuffer );
//void remove( void *pBuffer );
void search( void *pBuffer );
void list( void *pBuffer );

int main() {
    void *pBuffer = malloc(sizeof(int) * 2);
    *((int *)pBuffer) = 0; //Menu
    *((int *)pBuffer + 1) = 0; //Quantidade de pessoas
    
    for ( ; ; ) {
        menu( pBuffer );
        switch ( *((int *)pBuffer) )
        {
        case 1:
            add( pBuffer );
            break;
        case 2:
            //remove( pBuffer );
            break;
        case 3:
            search( pBuffer );
            break;
        case 4:
            list( pBuffer );
            break;
        case 5:
            exit(0);
            break;
        }
    }

    free(pBuffer);
    return 0;
}

void menu( void *pBuffer ) {

    do {
        printf("\t### Menu ###\n");
        printf("\t1.Adicionar Pessoa\n");
        printf("\t2.Remover Pessoa\n");
        printf("\t3.Buscar Pessoa\n");
        printf("\t4.Listar\n");
        printf("\t5.Sair\n");
        printf("Escolha: ");
        scanf( "%d",(int *)pBuffer);
        getchar();
    } while( *( (int *)pBuffer ) <= 0 || *( (int *)pBuffer ) > 5 );
}

void add( void *pBuffer) {

    (*( (int *)pBuffer + 1 ))++;

    pBuffer = realloc( pBuffer, ( 8 + (82 *( *( (int *)pBuffer + 1 ) ) ) ) );

    printf( "Digite o nome: " );
    fgets ( (char *)pBuffer + ( 8 + (82 *( *( (int *)pBuffer + 1 ) - 1 ) ) ), 32, stdin ); //Nome
    printf( "Digite o email: " );
    fgets( (char *)pBuffer + ( 40 + (82 *( *( (int *)pBuffer + 1 ) - 1 ) ) ), 46, stdin ); //Email
    printf( "Digite a idade: " );
    scanf( "%d", (int *)((char *)pBuffer + ( 86 + (82 *( *( (int *)pBuffer + 1 ) - 1 ) ) ) ) ); //Idade
    getchar();

}

void list( void *pBuffer ) {
    
    for ( *((int *)pBuffer) = 0;  *((int *)pBuffer) < *((int *)pBuffer + 1); ( *( (int *)pBuffer) )++ ) {
        printf("Posicao: %d", *(int*)pBuffer + 1);
        printf("\nNome: %s", (char *)pBuffer + ( 8 + (82 *( *( (int *)pBuffer) ) ) ) );
        printf("Email: %s", (char *)pBuffer + ( 40 + (82 *( *( (int *)pBuffer) ) ) ) );
        printf("Idade: %d\n", *((int *)((char *)pBuffer + ( 86 + (82 *( *( (int *)pBuffer ) ) ) ) ) ) );
    }

}

void search( void *pBuffer ) {

    void *email = (char *)pBuffer + ( 90 + (82 *( *( (int *)pBuffer + 1 ) ) ) );

    printf("Digite o email que quer procurar: ");
    //Email para comparar
    fgets( email, 46, stdin ); 

    for ( *((int *)pBuffer) = 0;  *((int *)pBuffer) < *((int *)pBuffer + 1); ( *( (int *)pBuffer) )++ ) {
        if(strcmp( (char *)email, (char *)pBuffer + ( 8 + (82 *( *( (int *)pBuffer) ) ) ) ) == 0) {
            //numeros e caracteres especiais não estao comparando
            printf("\nEste email esta na posicao de numero %d da agenda\n", *((int *)pBuffer + 1) );

            free(email);
            return;
        } 
    }

    printf("\nEste email nao esta na agenda\n");
    free(email);
}
