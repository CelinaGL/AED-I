#define MOD 1000000007

int d( int *nums, int numsSize, int **comb );
void combinacao( int n, int **comb );

int numOfWays(int* nums, int numsSize) {
    int r;

    int **comb = ( int ** )malloc( sizeof( int * ) * ( numsSize + 1 ) );
    for (int i = 0; i <= numsSize; i++) {
        comb[i] = ( int * )malloc( sizeof(int) * ( numsSize + 1 ) );
    }

    combinacao( numsSize, comb );
    r = d( nums, numsSize, comb ) - 1;

    for ( int i = 0; i <= numsSize; i++ ) {
        free(comb[i]);
    }
    free(comb);

    return r;
}

int d( int *nums, int numsSize, int **comb ) {
    int i, j = 0, k = 0, r, root;

    if ( numsSize <= 2 ) {
        return 1;
    }

    int left[numsSize];
    int right[numsSize];

    root = nums[0];

    for ( i = 1; i < numsSize; i++ ) {
        if ( root > nums[i] ) {
            left[j] = nums[i];
            j++;
        } else {
            right[k] = nums[i];
            k++;
        }
    }

    long long cesq, cdir;
    cesq = d( left, j, comb );
    cdir = d( right, k, comb );

    r = ( cesq * cdir ) % MOD * comb[j + k][j] % MOD;
    return r;
}

void combinacao( int n, int **comb ){
    int i, j;

    for ( i = 0; i <= n; i++ ) {
        comb[i][0] = 1; 
        comb[i][i] = 1;

        for ( j = 1; j < i; j++ ) {
            comb[i][j] = ( comb[i - 1][j - 1] + comb[i - 1][j] ) % MOD;
        }
    }
}