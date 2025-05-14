#include <stdbool.h>
#include <unistd.h>
#include <malloc.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies,
                      int* returnSize)
{
    int max = INT_MIN;
    for (int i = 0; i < candiesSize; ++i)
    {
        if (candies[i] > max)
            max = candies[i];
    }
    bool* track = (bool*)calloc(candiesSize, sizeof(bool));
    for (int i = 0; i < candiesSize; ++i)
    {
        track[i] = candies[i] + extraCandies >= max;
    }
    if (returnSize)
        *returnSize = candiesSize;
    return track;
}

int main(void)
{
    int candies[] = {2, 5, 3, 5, 1, 3};
    int candiesSize = sizeof(candies) / sizeof(*candies);
    int extraCandies = 3;
    kidsWithCandies(candies, candiesSize, extraCandies, NULL);
}