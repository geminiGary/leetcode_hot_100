int maxSubArray(int* nums, int numsSize) {
    int f[numsSize];
    f[0]=nums[0];
    for(int i=1;i<numsSize;i++)
    {
        f[i]=(f[i-1]>0)?f[i-1]+nums[i]:nums[i];
    }
    int max=f[0];
    for(int i=0;i<numsSize;i++)
    {
        max=(max>f[i])?max:f[i];
    }
    return max;
}
