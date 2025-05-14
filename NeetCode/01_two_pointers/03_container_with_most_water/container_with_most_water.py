from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1
        max_area = 0
        while l < r:
            area = (r - l) * min(height[l], height[r])
            if area > max_area:
                max_area = area
            if height[l] > height[r]:
                r -= 1
            else:
                l += 1
        return max_area
        

if __name__ == "__main__":
    solution = Solution()
    print(solution.maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7]))
