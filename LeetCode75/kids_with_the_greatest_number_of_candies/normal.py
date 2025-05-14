from typing import List

class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        greatest = max(candies)
        check = []
        for candy_count in candies:
            check.append(candy_count + extraCandies >= greatest)
        return check