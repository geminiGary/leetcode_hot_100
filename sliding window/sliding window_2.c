#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char* s, char* p, int* returnSize) {
    int *ans= (int *)malloc(sizeof(int) * strlen(s));
    int visit[26];
    for(int i=0;i<26;i++)
    {
        visit[i]=0;
    }
    for(int i=0;p[i]!='\0';i++)
    {
        visit[p[i]-'a']++;
    }
    int left=0;
    int right=0;
    int count=strlen(p);
    int index=0;
    while(s[right]!='\0')
    {
        if(visit[s[right]-'a']>0)
        {
            count--;
        }
        visit[s[right]-'a']--;
        right++;
        if(count==0)
        {
            ans[index++]=left;
        }
        if(right-left==strlen(p))
        {
            if(visit[s[left]-'a']>=0)
            {
                count++;
            }
            visit[s[left]-'a']++;
            left++;
        }
    }
    *returnSize=index;
    return ans;
}

int main() {
    char s[] = "cbaebabacd";
    char p[] = "abc";
    int returnSize;
    int* result = findAnagrams(s, p, &returnSize);
    printf("Starting indices of anagrams: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}