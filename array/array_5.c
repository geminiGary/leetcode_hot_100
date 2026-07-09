#include <stdio.h>

int firstMissingPositive(int* nums, int numsSize) {
    
}

int main() {
    int nums[] = {1, 2, 0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = firstMissingPositive(nums, numsSize);
    printf("%d\n", result);
    return 0;
}