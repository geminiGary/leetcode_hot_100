#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a,const void* b){
    return *(int*)a-*(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums,numsSize,sizeof(int),cmp);
    int **result=(int**)malloc(sizeof(int*)*100005);
    *returnSize=0;
    for(int i=0;i<numsSize-2;i++)
    {
        if(i>0&&nums[i]==nums[i-1])
        {
            continue;
        }
        else
        {
            int left=i+1;
            int right=numsSize-1;
            while(left<right)
            {
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==0)
                {
                    (*returnSize)++;
                    result[*returnSize-1]=(int*)malloc(sizeof(int)*3);
                    result[*returnSize-1][0]=nums[i];
                    result[*returnSize-1][1]=nums[left];
                    result[*returnSize-1][2]=nums[right];
                    left++;
                    right--;
                    while(left<right&&nums[left]==nums[left-1])
                    {
                        left++;
                    }
                    while(left<right&&nums[right]==nums[right+1])
                    {
                        right--;
                    }
                }
                else if(sum<0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }
    *returnColumnSizes=(int*)malloc(sizeof(int)*(*returnSize));
    for(int i=0;i<*returnSize;i++)    {
        (*returnColumnSizes)[i]=3;
    }    
    return result;
}

int main()
{
    int nums[]={-1,0,1,2,-1,-4};
    int returnSize;
    int *returnColumnSizes;
    int **result=threeSum(nums,6,&returnSize,&returnColumnSizes);
    for(int i=0;i<returnSize;i++)
    {
        printf("%d %d %d\n",result[i][0],result[i][1],result[i][2]);
    }
    return 0;
}