from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        exists: List[bool] = [False] * (len(nums) + 1)
        for num in nums:
            exists[num] = True
        for num in range(len(exists)):
            if exists[num] is False:
                return num
        return -1


if __name__ == "__main__":
    solution = Solution()
    print(solution.missingNumber([3, 0, 1]))
