#include <malloc.h>
#include <stdlib.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int minCostClimbingStairs(int* cost, int costSize)
{
    int* min_cost = (int*)calloc(costSize + 1, sizeof(int));
    for (int i = 2; i < costSize + 1; ++i)
    {
        min_cost[i] += min(min_cost[i - 1] + cost[i - 1],
                           min_cost[i - 2] + cost[i - 2]);
    }
    int min_cost_val = min_cost[costSize];
    free(min_cost);
    return min_cost_val;
}

int main(void)
{
    int cost[] = {10, 15, 20};
    int min_cost = minCostClimbingStairs(cost, sizeof(cost) / sizeof(cost[0]));
}