#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int longestConsecutive(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    if(numsSize == 0) return 0;
    int max = 1;
    int current_length = 1;
    for(int i = 1; i < numsSize; i++) {
        if(nums[i] == nums[i - 1]) {
            continue; // Skip duplicates
        } else if(nums[i] == nums[i - 1] + 1) {
            current_length++;
        } else {
            if(current_length > max) {
                max = current_length;
            }
            current_length = 1;
        }
    }
    if(current_length > max) {
        max = current_length;
    }
    return max;
}

int main() {
    int nums[] = {100, 4, 200, 1, 3, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    int result = longestConsecutive(nums, numsSize);
    printf("Longest consecutive sequence length: %d\n", result);
    
    return 0;
}