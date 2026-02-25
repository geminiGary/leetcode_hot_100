#include <stdio.h>

int trap(int* height, int heightSize) {
    int left=0;
    int right=heightSize-1;
    int left_max=height[0];
    int right_max=height[heightSize-1];
    int sum=0;
    while(left<right)
    {
        if(left_max<right_max)
        {
            left++;
            if(height[left]>left_max)
            {
                left_max=height[left];
            }
            else
            {
                sum+=left_max-height[left];
            }
        }
        else
        {
            right--;
            if(height[right]>right_max)
            {
                right_max=height[right];
            }
            else
            {
                sum+=right_max-height[right];
            }
        }
    }
    return sum;
}

int main() {
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int heightSize = sizeof(height) / sizeof(height[0]);
    int result = trap(height, heightSize);
    printf("Trapped water: %d\n", result);
    return 0;
}