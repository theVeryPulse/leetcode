from typing import List


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        min_cost = [0] * (len(cost) + 1)
        i = 2
        while i < len(min_cost):
            min_cost[i] = min(cost[i - 1] + min_cost[i - 1],
                              cost[i - 2] + min_cost[i - 2])
            i += 1
        return min_cost[-1]
