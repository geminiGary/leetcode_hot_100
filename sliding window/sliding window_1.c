#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int visit[128];
    for(int i = 0; i < 128; i++) {
        visit[i] = -1;
    }
    int current=0;
    int max=0;
    int left=0;
    visit[s[0]]=0;
    for(int i=1;s[i]!='\0';i++)
    {
        if(visit[s[i]]<left)
        {
            visit[s[i]]=i;
            current++;
        }
        else
        {
            if(current>max)
            {
                max=current;
            }
            left=visit[s[i]]+1;
            visit[s[i]]=i;
            current=i-left+1;
        }
    }
    if(current>max)
    {
        max=current;
    }
    return max;
}

int main() {
    char s[] = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    printf("Length of longest substring without repeating characters: %d\n", result);
    return 0;
}