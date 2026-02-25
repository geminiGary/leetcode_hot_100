#include<stdio.h>
#include<stdlib.h>

void sortColors(int* nums, int numsSize) {
    int left=0;
    int right=numsSize-1;
    for(int i=0;i<=right;i++)
    {
        if(nums[i]==0)
        {
           int temp=nums[i];
           nums[i]=nums[left];
           nums[left]=temp;
           left++;
           continue; 
        }
        if(nums[i]==2)
        {
            int temp=nums[i];
            nums[i]=nums[right];
            nums[right]=temp;
            right--; 
            continue;
        }
    }
    for(int i=0;i<numsSize;i++) printf("%d ",nums[i]);
    return;
}

int main()
{
    int nums[]={2,0,2,1,1,0};
    sortColors(nums,6);
    return 0;
}