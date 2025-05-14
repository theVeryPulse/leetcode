from typing import List, Set


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        def calc_area(length, width): return length * width
        stack: List[Set[int, int]] = list()  # Index and height
        largest_area = 0
        for i, height in enumerate(heights):
            leftmost = i
            while stack and stack[-1][1] > height:
                area = calc_area(i - stack[-1][0], stack[-1][1])
                largest_area = max(largest_area, area)
                leftmost = stack.pop()[0]
            stack.append((leftmost, height))
        for i, height in stack:
            area = calc_area(len(heights) - i, height)
            largest_area = max(largest_area, area)
        return largest_area


if __name__ == "__main__":
    heights = [2, 1, 5, 6, 2, 3]
    solution = Solution()
    print(solution.largestRectangleArea(heights))
    print(solution.largestRectangleArea([2, 1, 2]))
