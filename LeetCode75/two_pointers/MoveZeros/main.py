from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if type(nums) is list:
            nums.sort(key=lambda num: 0 if num != 0 else 1)

if (__name__ == "__main__"):
    sol = Solution()
    nums = [1, 0, 3]
    sol.moveZeroes(nums)
    print(nums)