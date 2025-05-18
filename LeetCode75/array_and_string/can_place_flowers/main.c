#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n)
{
    if (flowerbedSize == 1)
        return ((flowerbed[0] == 0) ? 1 : 0) >= n;

    int total = 0;
    int i = 0;
    while (i < flowerbedSize)
    {
        if (i == 0)
        {
            if (flowerbed[i] == 0 && flowerbed[i + 1] == 0)
            {
                ++total;
                ++i;
            }
        }
        else if (i == flowerbedSize - 1)
        {
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0)
            {
                ++total;
                ++i;
            }
        }
        else if (flowerbed[i - 1] == 0 && flowerbed[i] == 0
                 && flowerbed[i + 1] == 0)
        {
            ++total;
            ++i;
        }
        ++i;
    }
    return n <= total;
}

#include <stdio.h>

int main(void)
{
    int  flowerbed[] = {1, 0, 0, 0, 1};
    bool result = canPlaceFlowers(flowerbed,
                                  sizeof(flowerbed) / sizeof(flowerbed[0]), 2);
    printf("%d\n", result);
}