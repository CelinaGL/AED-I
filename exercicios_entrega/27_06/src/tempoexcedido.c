#define MAX 100000

typedef struct {
    char fita[MAX];
    int topo;
    int base;
    int limite;
} Pilha; 

Pilha *criaPilha() {
    Pilha *pilha = (Pilha *)malloc( sizeof( Pilha ) );
    pilha->topo = 0;
    pilha->base = 0;
    pilha->limite = MAX;
    return pilha;
}

bool empyt( Pilha *pilha ) {
    return pilha->topo == 0;
}

bool full( Pilha *pilha ) {
    return pilha->topo == MAX;
}

bool push( Pilha *pilha, char s ) {
    if ( !full(pilha) ) {
        pilha->fita[pilha->topo] = s;
        pilha->topo++;
        return true;
    } else {
        return false;
    }
}

void pop( Pilha *pilha, char *a_b ) {
    if ( !empyt(pilha) ) {
        pilha->topo--;
        *a_b = pilha->fita[pilha->topo];
    }
}

void reset( Pilha *pilha ) {
    pilha->topo = 0;
    pilha->base = 0;
    pilha->limite = MAX;
}

int contar( int xy, Pilha *p, Pilha *o, char ab1, char ab2 ) {
    int resultado = 0, i; 
    char t1, t2;
    
    while ( !empyt(p) ) {
         pop( p, &t1 );
        if ( t1 == ab1 && !empyt(o) ) {
            pop(o, &t2);
             if ( t2 == ab2 ) {
                resultado = resultado + xy;
            } else {
                push( o, t2 );
                push( o, t1 );
            }
        } else {
        push( o, t1 );
        }
    }

    reset(p);
    while ( !empyt(o) ) { //esse é o problema
        pop( o, &t1 );
        push( p, t1 );
        }
    reset(o);
    return resultado;
}

int maximumGain(char* s, int x, int y) {
    int r = 0, i;
    char l;
    Pilha *p = criaPilha();
    Pilha *o = criaPilha();

    for ( i = 0; i < strlen(s) ; i++ ) {
        l = s[i];
        push( p, l );
    }

    if ( x >= y ) {
        r = r + contar( x, p, o, 'a', 'b' );
        r = r + contar( y, p, o, 'b', 'a' );
    } else {
        r = r + contar( y, p, o, 'b', 'a' );
        r = r + contar( x, p, o, 'a', 'b' );
    }
        
    free(p);
    free(o);
    return r;
}