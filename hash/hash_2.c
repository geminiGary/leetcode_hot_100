#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    
}

int main() {
    char* strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int strsSize = sizeof(strs) / sizeof(strs[0]);
    int returnSize;
    int* returnColumnSizes;
    
    char*** result = groupAnagrams(strs, strsSize, &returnSize, &returnColumnSizes);
    
    printf("Grouped Anagrams:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%s", result[i][j]);
            if (j < returnColumnSizes[i] - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
    
    // Free allocated memory (not shown here)
    
    return 0;
}