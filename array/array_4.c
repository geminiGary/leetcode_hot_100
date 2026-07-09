/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *result = (int*)malloc(sizeof(int) * numsSize);
    int preMul[100005], sufMul[100005];
    preMul[0] = nums[0];
    sufMul[numsSize - 1] = nums[numsSize - 1];
    for (int i = 1; i < numsSize; i++) {
        preMul[i] = preMul[i - 1] * nums[i];
        sufMul[numsSize - 1 - i] = sufMul[numsSize - i] * nums[numsSize - 1 - i];
    }
    for (int i = 0; i < numsSize; i++) {
        if (i == 0) {
            result[i] = sufMul[1];
        } else if (i == numsSize - 1) {
            result[i] = preMul[numsSize - 2];
        } else {
            result[i] = preMul[i - 1] * sufMul[i + 1];
        }
    }
    *returnSize = numsSize;
    return result;
}

int main() {
    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *result = productExceptSelf(nums, numsSize, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}