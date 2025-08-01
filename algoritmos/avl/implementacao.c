#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Treenode{
    int val;
    struct Treenode *left;
    struct Treenode *right;
};

typedef struct Treenode Nodo;

int Altura( Nodo *root );
int FB( Nodo *root );
int Balanceamento( Nodo **root );
void RSE( Nodo **root );
void RSD( Nodo **root );
int BalancaEsq( Nodo **root );
int BalancaDir( Nodo **root );
int Insere( Nodo **root, int x );


int main(){
    srand(time(0));
    Nodo *root = NULL;
    int i, n, x, r;

    printf("Digite a quantidade de nodos da arvore: ");
    scanf("%d", &n);

    for ( i = 0; i < n; i++ ) {
        //x = rand();
        scanf("%d", &x);
        r = Insere( &root, x );
    }

    printf("%d ", root->val );
    printf("%d ", root->left->val );
    printf("%d ", root->right->val );

    return 0;
}

int Altura( Nodo *root ) {
    int esq, dir;

    if ( root == NULL ) {
        return 0;
    }

    esq = Altura( root->left );
    dir = Altura( root->right );

    if ( esq > dir ) {
        return esq + 1;
    } else {
        return dir + 1;
    }

}

int FB( Nodo *root ) {
    if ( root == NULL ){
        return 0;
    }
    return Altura( root->left ) - Altura( root->right );
}

int Balanceamento( Nodo **root ) {
    int fb = FB( *root );

    if ( fb > 1 ) {
        BalancaEsq( root );
    } else if ( fb < -1 ) {
        BalancaDir( root );
    } else {
        return 0;
    }

}

void RSE( Nodo **root ) {
    Nodo *temp;

    temp = (*root)->right;
    (*root)->right = temp->left;
    temp->left = (*root);
    (*root) = temp;

}

void RSD( Nodo **root ) {
    Nodo *temp;

    temp = (*root)->left;
    (*root)->left = temp->right;
    temp->right = (*root);
    (*root) = temp;

}

int BalancaEsq( Nodo **root ) {
    int fb = FB( (*root)->left );

    if ( fb > 0 ) {
        RSD( root );
        return 1;
    } else if ( fb < 0 ) {
        RSE( &( (*root)->left ) );
        RSD( root );
        return 1;
    }

    return 0;

}

int BalancaDir( Nodo **root ) {
    int fb = FB( (*root)->right );

    if ( fb < 0 ) {
        RSE( root );
        return 1;
    } else if ( fb > 0 ) {
        RSD( &( (*root)->right ) );
        RSE( root );
        return 1;
    }

    return 0;

}

int Insere( Nodo **root, int x ) {
    if (*root == NULL) {
        *root = ( Nodo * )malloc( sizeof(Nodo) );
        (*root)->val = x;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return 1;

    } else if ( (*root)->val > x ) {

            if ( Insere( &(*root)->left, x ) ) {

                if (Balanceamento(root))
                    return 0;
                else
                return 1;

            }
        } else if ( (*root)->val < x ) {

                if ( Insere( &(*root)->right, x ) ) {

                    if (Balanceamento(root))
                        return 0;
                    else
                        return 1;

                } else
                    return 0;

            } else
                return 0; 
}
