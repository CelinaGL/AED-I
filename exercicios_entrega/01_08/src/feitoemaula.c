int d( int *nums, int numsSize );
int numOfWays(int* nums, int numsSize) {
    int r;

    r = d( nums, numsSize );

    return r;
}

int d( int *nums, int numsSize ) {
    int i, j = 0, k = 0, r, root;
    int left[numsSize - 1];
    int right[numsSize - 1];

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

    if ( j == (numsSize - 1) || k == (numsSize - 1) ) {
        return 1;
    }
    
    r = ( left, j ) * ( right, k );
    return r;
}