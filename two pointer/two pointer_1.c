#include <stdio.h>
#include <stdlib.h>

void moveZeroes(int* nums, int numsSize) {
    int left=0;
    int right=0;
    while (right<numsSize)
    {
        if(nums[right]!=0)
        {
            nums[left]=nums[right];
            left++;
        }
        right++;
    }
    while (left<numsSize)
    {
        nums[left]=0;
        left++;
    }
    for(int i=0;i<numsSize;i++)
    {
        printf("%d ",nums[i]);
    }
    return;
}

int main()
{
    int nums[]={0,1,0,3,12};
    int numsSize=sizeof(nums)/sizeof(nums[0]);
    moveZeroes(nums,numsSize);
    return 0;
}