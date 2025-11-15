#include <math.h>

inline static void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void moveZeroes(int* nums, int numsSize)
{
    int non_zero = 0;
    int zero = 0;
    while (zero < numsSize && non_zero < numsSize)
    {
        // Find next zero
        while (zero < numsSize && nums[zero] != 0)
            zero++;
        if (zero >= numsSize)
            return;

        // Find next non-zero
        while (non_zero < numsSize && nums[non_zero] == 0)
            non_zero++;
        if (non_zero >= numsSize)
            return;

        // For cases like [1, 0, 1], where the array is not done, but a 0 is
        // after a 1
        if (zero > non_zero)
        {
            non_zero = zero + 1;
            continue;
        }

        swap(&nums[zero], &nums[non_zero]);

        
    }
}

#include <stdio.h>

int main(void)
{
    // Input: nums = [0,1,0,3,12]
    // Output: [1,3,12,0,0]
    // int nums[] = {0, 1, 0, 3, 12};
    // int nums[] = {1, 0};
    int nums[] = {1, 0, 1};
    int size = (int)(sizeof(nums) / sizeof(nums[0]));

    moveZeroes(nums, size);

    for (int i = 0; i < size; i++)
        printf("%d\n", nums[i]);
}