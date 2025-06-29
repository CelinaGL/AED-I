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

int contar1( char *s, int xy, Pilha *p, char ab1, char ab2 ) {
    int resultado = 0, i, tam = strlen(s);
    char l, c;

    for ( i = 0; i < tam ; i++ ) {
        l = s[i];
        if ( l == ab2 && !empyt(p) ){
            pop( p, &c );
            if ( c == ab1 ){
            resultado = resultado + xy;
            } else {
                    push( p, c );
                    push( p, l );
            }
        } else {
             push( p, l );
        }
    }

    return resultado;
}

int contar2( int xy, Pilha *p, Pilha *o, char ab1, char ab2 ) {
    int resultado = 0, i; 
    char t1, t2;

        while ( !empyt(p) ) {
            pop( p, &t1 );
            if ( t1 == ab1 && !empyt(o) ) {
                pop(o, &t2);
                if ( t2 == ab2 ) {
                    resultado = resultado + xy;
                } else {
                    push( o, t1 );
                }
            } else {
            push( o, t1 );
            }
        }

    return resultado;
}

int maximumGain(char* s, int x, int y) {
    int r = 0;
    Pilha *p = criaPilha();
    Pilha *o = criaPilha();

    if ( x >= y ) {
        r = r + contar1( s, x, p, 'a', 'b' );
        r = r + contar2( y, p, o, 'b', 'a' );

    } else {
        r = r + contar1( s, y, p, 'b', 'a' );
        r = r + contar2( x, p, o, 'a', 'b' );
    }
        
    free(p);
    free(o);
    return r;
}