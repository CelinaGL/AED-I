/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    int i, re = 0;
    
    for (i = 0; i<numsSize; i++) {
        re = re + nums[i];
        nums[i] = re;
    }
    *returnSize = numsSize;
    return nums;
}