from typing import List

class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        greatest = max(candies)
        check = [candy_count + extraCandies >= greatest for candy_count in candies]
        return check