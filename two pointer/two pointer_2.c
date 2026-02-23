#include <stdio.h>
#include <stdlib.h>

int maxArea(int* height, int heightSize) {
    int left=0;
    int right=heightSize-1;
    int max=0;
    while(left<right)
    {
        int currentArea=(right-left)*((height[left]<height[right])?height[left]:height[right]);
        if(currentArea>max)
        {
            max=currentArea;
        }
        if(height[left]<height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return max;
}

int main()
{
    int height[]={1,8,6,2,5,4,8,3,7};
    int heightSize=sizeof(height)/sizeof(height[0]);
    int result=maxArea(height,heightSize);
    printf("%d",result);
    return 0;
}