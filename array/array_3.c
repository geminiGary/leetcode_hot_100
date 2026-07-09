#include <stdio.h>
#include <stdlib.h>

void rotate1(int* nums, int numsSize, int k) {
    int rotate = k % numsSize;
    int *temp = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        temp[i] = nums[(i + numsSize - rotate) % numsSize];
    }
    for (int i = 0; i < numsSize; i++) {
        nums[i] = temp[i];
    }
    free(temp);
    return;
}

void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate2(int *nums, int numsSize, int k) {
    k %= numsSize;
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
    return;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;
    rotate2(nums, numsSize, k);
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}