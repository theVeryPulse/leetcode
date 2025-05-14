from typing import List

# Reference: https://www.youtube.com/watch?v=ZI2z5pq0TqA

class Solution:
    def trap(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1
        l_max = 0
        r_max = 0
        volume = 0
        while l <= r:
            if l_max <= r_max:
                water_in_column = min(l_max, r_max) - height[l]
                if water_in_column > 0:
                    volume += water_in_column
                if height[l] > l_max:
                    l_max = height[l] 
                l += 1
            else:
                water_in_column = min(l_max, r_max) - height[r]
                if water_in_column > 0:
                    volume += water_in_column
                if height[r] > r_max:
                    r_max = height[r] 
                r -= 1
                
        return volume

if __name__ == "__main__":
    solution = Solution()
    print(solution.trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]), ": should be 6")
    print(solution.trap([4,2,0,3,2,5]), ": should be 9")
    print(solution.trap([4,2,3]))
    print(solution.trap([5,4,1,2]))
    print(solution.trap([4,9,4,5,3,2]))
    