#define MAX 100

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
    if ( !full ) {
        pilha->fita[pilha->topo] = s;
        pilha->topo++;
        return true;
    } else {
        return false;
    }
}

void pop( Pilha *pilha, char *ab_ba ) {
    if ( !empyt(pilha) ) {
        pilha->topo--;
        *a_b = pilha->f[pilha->topo];
    }
}

void reset( Pilha *pilha ) {
    pilha->topo = 0;
    pilha->base = 0;
    pilha->limite = MAX;
}

int maximumGain(char* s, int x, int y) {
    int r = 0, i;
    //char *aby = "ab", *bax = "ba";
    char a = 'a', b = 'b';
    char l;
    Pilha *p = criaPilha();
    Pilha *o = criaPilha();

    for ( i = 0; i < strlen(s); i++ ) {
        l = s[i];
        push( p, l );
    }

    for ( i = 0; i < strlen(s)/2; i++ ) {
        char *t1, *t2;
        pop( p, t1 );

        if ( strcmp( t1, a ) ) {
            pop( p, t2 );
            if ( strcmp( t2, b ) ) {
                r = r + y;
            } else {
                push( o, t1 )
            }
            if ( strcmp( t2, a ) ) {

            }
            //while( t1 )
        }
    }
    return r;
}