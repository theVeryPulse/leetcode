from typing import List

class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        small = float('inf')
        mid = small

        for num in nums:
            if num < small:
                small = num
            elif num < mid and num > small:
                mid = num
            elif num > mid:
                return True
            
        return False

if __name__ == "__main__":
    nums = [1, 1, -2, 6]
    solution = Solution()
    print(solution.increasingTriplet(nums))