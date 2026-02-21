#include <stdio.h>
#include <stdlib.h>

int a[1000000005][2];

int longestConsecutive(int* nums, int numsSize) {
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]<0)
        {
            a[-nums[i]][0]=1;
        }
        else
        {
            a[nums[i]][1]=1;
        }
    }
    int max=0;
    int ans=0;
    for(int i=100000000;i>=0;i--)
    {
        if(a[i][0]==1)
        {
            ans++;
        }
        else
        {
            if(ans>max)
            {
                max=ans;
            }
            ans=0;
        }
    }
    for(int i=1;i<=100000000;i++)
    {
        if(a[i][1]==1)
        {
            ans++;
        }
        else
        {
            if(ans>max)
            {
                max=ans;
            }
            ans=0;
        }
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