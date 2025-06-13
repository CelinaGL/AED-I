#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cabeca (sizeof(int) * 2 + sizeof(char) * 32)
#define nomeP (sizeof(char) * 32)
#define emailP (sizeof(char) * 46)
#define idadeP sizeof(int)
#define pessoa (nomeP + emailP + idadeP)

void menu( void *pBuffer );
void add( void **pBuffer );
void remover( void **pBuffer );
void search( void *pBuffer );
void list( void *pBuffer );

int main() {
    void *pBuffer = malloc(sizeof(int) * 3 + sizeof(char) * 110 );
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
            remover( &pBuffer );
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

    void *novopBuffer = realloc( *pBuffer, cabeca + ( (*quantidade) * pessoa ) );

    *pBuffer = novopBuffer;
    quantidade = (int *)(*pBuffer) + 1;

    void *nome = ( char * )(*pBuffer) + ( cabeca + ( ( (*quantidade) - 1) * pessoa ) );
    void *email = nome + nomeP;
    void *idade = ( int * )(email + emailP);

    printf("Nome: ");
    //fgets( nome, 32, stdin );
    scanf("%[^\n]s", nome);
    getchar();
    printf("Email: ");

    scanf("%[^\n]s", email);
    getchar();
    printf("Idade: ");
    scanf("%d", idade);

}

void list( void *pBuffer ) {
    for ( *((int *)pBuffer) = 0;  *((int *)pBuffer) < *((int *)pBuffer + 1); ( *( (int *)pBuffer) )++ ) {
        printf("\nPosicao: %d", *(int*)pBuffer + 1);
        printf("\nNome: %s\n", (char *)pBuffer + ( cabeca + (pessoa *( *( (int *)pBuffer) ) ) ) );
        printf("Email: %s\n", (char *)pBuffer + ( cabeca + nomeP + (pessoa *( *( (int *)pBuffer) ) ) ) );
        printf("Idade: %d\n", *((int *)((char *)pBuffer + ( cabeca + nomeP + emailP + (pessoa *( *( (int *)pBuffer ) ) ) ) ) ) );
    }

}

void search( void *pBuffer ) {
    int *contador = (int *)pBuffer;
    int *quantidade = (int *)pBuffer + 1;
    char *nome = (char *)pBuffer + 8 + (pessoa * (*quantidade) );

    printf("Digite o nome da pessoa que quer procurar: ");
    //Nome para comparar
    scanf("%[^\n]s", nome);

    for ( *contador = 0;  *contador < *quantidade; (*contador)++) {
        if(strcmp( nome, (char *)pBuffer + ( cabeca + (pessoa *( *contador ) ) ) ) == 0) {
            printf("\nEsta pessoa esta na posicao de numero %d da agenda\n", *contador + 1 );
            printf("Email: %s\n", (char *)pBuffer + ( cabeca + nomeP + (pessoa *( *contador ) ) ) );
            printf("Idade: %d\n", *((int *)((char *)pBuffer + ( cabeca + nomeP + emailP + (pessoa *( *contador ) ) ) ) ) );
            
            return;
        } 
    }

    printf("\nEsta pessoa nao esta na agenda\n");
}

void remover( void **pBuffer ) {
    int *contador = (int *)(*pBuffer);
    int *quantidade = (int *)(*pBuffer) + 1;
    char *nome = (char *)(*pBuffer) + 8 + (pessoa * (*quantidade));

    printf("Digite o nome da pessoa que quer remover: ");
    //Nome para comparar
    scanf("%[^\n]s", nome);

    for ( *contador = 0;  *contador < *quantidade; (*contador)++) {
        if(strcmp( nome, (char *)(*pBuffer) + ( cabeca + (pessoa *( *contador ) ) ) ) == 0) {
            
            if (*contador < (*quantidade - 1)) {
                void *remover = (char *)(*pBuffer) + cabeca + (pessoa * (*contador));
                void *manter = (char *)remover + pessoa;

                memmove(remover, manter, pessoa * ((*quantidade) - (*contador) - 1));
            }
            (*quantidade)--;
            void *novopBuffer = realloc( *pBuffer, cabeca + (pessoa * ( *quantidade ) ) );
            *pBuffer = novopBuffer;
            printf("\nEsta pessoa foi removida\n");
            return;
        } 
    }

     printf("\nEsta pessoa nao esta na agenda\n");
}
