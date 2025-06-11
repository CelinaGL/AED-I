#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu( void *pBuffer );
void add( void **pBuffer );
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
            add( &pBuffer );
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
            free(pBuffer);
            exit(0);
            break;
        }
    }

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

void add( void **pBuffer ) {
    int *quantidade = (int *)(*pBuffer) + 1;
    (*quantidade)++;

    void *novopBuffer = realloc( *pBuffer, 8 + (82 * ( *quantidade ) ) );

    *pBuffer = novopBuffer;

    void *nome = ( char * )(*pBuffer) + 8 + (82 * ( ( *quantidade ) - 1 ) );
    void *email = nome + 32;
    void *idade = ( int * )(email + 46);

    printf("Nome: ");
    fgets( nome, 32, stdin );
    printf("Email: ");
    fgets( email, 46, stdin );
    printf("Idade: ");
    scanf("%d", idade);

}

void list( void *pBuffer ) {
    
    for ( *((int *)pBuffer) = 0;  *((int *)pBuffer) < *((int *)pBuffer + 1); ( *( (int *)pBuffer) )++ ) {
        printf("\nPosicao: %d", *(int*)pBuffer + 1);
        printf("\nNome: %s", (char *)pBuffer + ( 8 + (82 *( *( (int *)pBuffer) ) ) ) );
        printf("Email: %s", (char *)pBuffer + ( 40 + (82 *( *( (int *)pBuffer) ) ) ) );
        printf("Idade: %d\n", *((int *)((char *)pBuffer + ( 86 + (82 *( *( (int *)pBuffer ) ) ) ) ) ) );
    }

}

void search( void *pBuffer ) {

    char *nome = (char *)pBuffer + 8 + (82 * (*(int *)((int *)pBuffer + 1)));
    int *contador = (int *)pBuffer;
    int *quantidade = (int *)pBuffer + 1;

    printf("Digite o nome da pessoa que quer procurar: ");
    //Nome para comparar
    fgets( nome, 32, stdin ); 

    for ( *contador = 0;  *contador < *quantidade; (*contador)++) {
        if(strcmp( (char *)nome, (char *)pBuffer + ( 8 + (82 *( *contador ) ) ) ) == 0) {
            printf("\nEsta pessoa esta na posicao de numero %d da agenda\n", *((int *)pBuffer + 1) );
            return;
        } 
    }

    printf("\nEsta pessoa nao esta na agenda\n");
}

