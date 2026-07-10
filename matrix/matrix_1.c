#include <stdio.h>
#include <stdlib.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int firstLineHaveZero = 0;
    int firstRoutineHaveZero = 0;
    for (int i = 0; i < matrixSize; i++) {
        if (matrix[i][0] == 0) {
            firstRoutineHaveZero = 1;
            break;
        }
    }
    for (int j = 0; j < matrixColSize[0]; j++) {
        if (matrix[0][j] == 0) {
            firstLineHaveZero = 1;
            break;
        }
    }
    for (int i = 1; i < matrixSize; i++) {
        for (int j = 1; j < matrixColSize[i]; j++) {
            int integer = matrix[i][j];
            if (integer == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < matrixSize; i++) {
        if (matrix[i][0] == 0) {
            for (int j = 1; j < matrixColSize[i]; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    for (int j = 1; j < matrixColSize[0]; j++) {
        if (matrix[0][j] == 0) {
            for (int i = 1; i < matrixSize; i++) {
                matrix[i][j] = 0;
            }
        }
    }
    if (firstLineHaveZero) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            matrix[0][j] = 0;
        }
    }
    if (firstRoutineHaveZero) {
        for (int i = 0; i < matrixSize; i++) {
            matrix[i][0] = 0;
        }
    }
    return;
}

int main() {
    int matrixSize = 4;
    int* matrixColSize = (int *)malloc(matrixSize * sizeof(int));
    int matrix[4][4] = {{1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0}};
    for (int i = 0; i < matrixSize; i++) {
        matrixColSize[i] = 4;
    }
    int** data = malloc(matrixSize * sizeof(int*));
    for (int i = 0; i < matrixSize; i++) {
        data[i] = malloc(matrixColSize[i] * sizeof(int));
    }
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            data[i][j] = matrix[i][j];
        }
    }
    setZeroes(data, matrixSize, matrixColSize);
    printf("Output:\n");
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
    free(matrixColSize);
    return 0;
}