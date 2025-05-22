struct q {
    int valor, conta;
};
typedef struct q valores;

int singleNumber(int* nums, int numsSize) {
    int i, j, temp, tamanho = 0;
    valores *quantidade;
    quantidade = ( valores* )malloc(numsSize * sizeof(valores));

    for ( i = 0; i < numsSize; i++ ) {
        temp = nums[i];
        quantidade[i].valor = nums[i];
        quantidade[i].conta = 0;
        for ( j = 0; j < numsSize; j++ ) {
            if ( nums[j] == temp ){
            quantidade[i].conta = quantidade[i].conta + 1;
            tamanho++;
            }
        }
    }

    for ( i = 0; i < tamanho; i++ ) {
        if ( quantidade[i].conta == 1 ) {
            return quantidade[i].valor;
        }
    }
    return 0;
}