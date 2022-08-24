#include <stdio.h>

int helper(int nums[], int l, int r, int target)
{
    if (l == r)
        return (target == nums[l]) ? l : -1;
    
    int m = l + (r - l) / 2;
    if (nums[l] <= nums[m])
    {
        if (nums[m] >= target && target >= nums[l])
        {
            return helper(nums, l, m, target);
        }
        else
        {
            return helper(nums, m+1, r, target);
        }
    }
    else
    {
        if (nums[r] >= target && target >= nums[m])
        {
            return helper(nums, m, r, target);
        }
        else
        {
            return helper(nums, l, m-1, target);
        }
    }
}

int search(int* nums, int numsSize, int target)
{
    return helper(nums, 0, numsSize-1, target);
}

int main(int argc, char *argv[])
{
    int array[] = {5, 1, 2, 3, 4};
	int len = sizeof(array)/sizeof(array[0]);
    printf("1: %d\n", search(array, len, 1));
    printf("2: %d\n", search(array, len, 2));
    printf("3: %d\n", search(array, len, 3));
    printf("4: %d\n", search(array, len, 4));
    printf("5: %d\n", search(array, len, 5));
    printf("6: %d\n", search(array, len, 6));
    printf("7: %d\n", search(array, len, 7));
    printf("8: %d\n", search(array, len, 8));
}