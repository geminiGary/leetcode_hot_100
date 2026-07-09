#include <stdio.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int *result = (int*)malloc((numsSize - k + 1) * sizeof(int));
    int deque[numsSize];
    int front = 0, rear = 0;
    for (int i = 0; i < numsSize; i++) {
        while (front < rear && nums[deque[rear - 1]] <= nums[i]) {
            rear--;
        }
        deque[rear++] = i;
        if (i >= k - 1) {
            result[i - k + 1] = nums[deque[front]];
            if (deque[front] <= i - k + 1) {
                front++;
            }
        }
    }
    *returnSize = numsSize - k + 1;
    return result;
}