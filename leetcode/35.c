int searchInsert(int* nums, int numsSize, int target) {
    int x, i;

    for ( x = 0; x < numsSize; x++ ) {
        if ( nums[x] == target ) {
            return x;
        } else {
            if ( nums[x] < target ) {
                i = x + 1;
            } 
        }
    }

    return i;
}