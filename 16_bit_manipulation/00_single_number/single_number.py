from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        single: int = 0
        for num in nums:
            single ^= num
        return single