#include <stdio.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    int *intv1 = *(int**)a;
    int *intv2 = *(int**)b;
    int v1 = intv1[0];
    int v2 = intv2[0];
    if (v1 < v2) return -1;
    else if (v1 > v2) return 1;
    else return intv1[1] - intv2[1];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    int start[10005], end[10005];
    qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);
    int idx = 0;
    start[idx] = intervals[0][0];
    end[idx] = intervals[0][1];
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] <= end[idx]) {
            end[idx] = end[idx] > intervals[i][1] ? end[idx] : intervals[i][1];
        } else {
            idx++;
            start[idx] = intervals[i][0];
            end[idx] = intervals[i][1];
        }
    }
    *returnSize = idx + 1;
    int *resultColSize = (int*)malloc(sizeof(int) * (*returnSize));
    int **result = (int**)malloc(sizeof(int*) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        resultColSize[i] = 2;
        result[i] = (int*)malloc(sizeof(int) * 2);
        result[i][0] = start[i];
        result[i][1] = end[i];
    }
    *returnColumnSizes = resultColSize;
    return result;
}

int main() {
    printf(merge(NULL, 0, NULL, NULL, NULL));
}