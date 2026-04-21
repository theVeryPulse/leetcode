#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool increasingTriplet(int* nums, int numsSize)
{
    if (!nums || numsSize <= 0)
        return false;

    int small = INT_MAX;
    int mid = INT_MAX;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] < small)
            small = nums[i];
        else if (nums[i] < mid && nums[i] > small)
            mid = nums[i];
        else if (nums[i] > mid)
            return true;
    }

    return false;
}

int main(void)
{
    int nums[] = {1,1,-2,6};
    int size = (int)(sizeof(nums) / sizeof(nums[0]));
    printf("Result: %d\n", increasingTriplet(nums, size));
}