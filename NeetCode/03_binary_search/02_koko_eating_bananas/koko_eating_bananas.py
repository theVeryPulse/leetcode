from typing import List
import math


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def k_works(k: int) -> bool:
            total_hours = sum(math.ceil(pile / k) for pile in piles)
            return total_hours <= h
        lower = 1
        higher = max(piles)
        min_k = 1
        while lower <= higher:
            mid = (lower + higher) // 2
            if k_works(mid):  # Try less k
                min_k = mid
                higher = mid - 1
            else:  # Try greater k
                lower = mid + 1
        return min_k


if __name__ == "__main__":
    solution = Solution()

    piles = [3, 6, 7, 11]
    h = 8
    print(solution.minEatingSpeed(piles, h))

    piles = [30, 11, 23, 4, 20]
    h = 5
    print(solution.minEatingSpeed(piles, h))

    piles = [30, 11, 23, 4, 20]
    h = 6
    print(solution.minEatingSpeed(piles, h))

    piles = [312884470]
    h = 312884469
    print(solution.minEatingSpeed(piles, h))
