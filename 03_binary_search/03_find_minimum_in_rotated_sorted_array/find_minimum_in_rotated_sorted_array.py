from typing import List


class Solution:
    def avg(self, a: int, b: int):
        return (a + b) // 2

    def findMin(self, nums: List[int]) -> int:
        if len(nums) == 1 or nums[0] < nums[-1]:
            return nums[0]
        if len(nums) == 2:
            return min(nums[0], nums[1])
        l: int = 0
        r: int = len(nums) - 1
        m: int = self.avg(l, r)
        while True:
            if l + 1 == m and nums[l] > nums[m]:
                return nums[m]
            elif m + 1 == r and nums[m] > nums[r]:
                return nums[r]

            if nums[l] < nums[m]:
                l = m
            else:
                r = m
            m = self.avg(l, r)
