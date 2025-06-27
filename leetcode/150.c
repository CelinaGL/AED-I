#define MAX 10000

typedef struct {
    int n[MAX];
    int topo;
    int base;
    int limite;
} Pilha;

Pilha *criaPilha() {
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->base = 0;
    p->limite = MAX;
    p->topo = 0;

    return p;
}

bool full( Pilha *pilha ) {
    return pilha->topo == MAX;
}

bool empty( Pilha *pilha ) {
    return pilha->topo == 0;
}

bool push( Pilha *pilha, int num ){
    if ( !full(pilha) ) {
        pilha->n[pilha->topo] = num;
        pilha->topo++;
        return true;
    } else {
        return false;
    }
}

void pop( Pilha *pilha, int *num ) {
    if ( !empty(pilha) ) {
        pilha->topo--;
        *num = pilha->n[pilha->topo];
    }
}

void reset( Pilha *pilha ) {
    pilha->topo = 0;
    pilha->base = 0;
    pilha->limite = MAX;
}

int evalRPN( char** tokens, int tokensSize ) {
    int i, x = 0, y = 0;

    Pilha *p = criaPilha();

    for ( i = 0; i < tokensSize; i++ ) {
        char *t = tokens[i]; 
        
        if ( (strcmp(t, "+") == 0) || (strcmp(t, "-") == 0) || 
             (strcmp(t, "/") == 0) || (strcmp(t, "*") == 0) ) {

            pop( p, &x );
            pop( p, &y );

            if ((strcmp(t, "+") == 0)){
                x = y + x;
            }

            if ((strcmp(t, "-") == 0)){
                x = y - x;
            }
            
            if ((strcmp(t, "/") == 0)){
                x = y / x;
            }

            if ((strcmp(t, "*") == 0)){
                x = y * x;
            }

            push( p, x );

        } else {
            push( p, atoi(t));
        }
    }
    pop(p, &x);
    free(p);
    return x;
}