from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        def mean(a, b): return int((a + b) / 2)
        begin = 0
        end = len(matrix)
        mid = mean(begin, end)
        while begin != mid:
            if matrix[mid][0] == target:
                return True
            elif matrix[mid][0] > target:
                end = mid
                mid = mean(begin, end)
            else:  # matrix[mid][0] < target
                begin = mid
                mid = mean(begin, end)

        nums: List[int] = matrix[mid]
        begin = 0
        end = len(nums)
        mid = mean(begin, end)
        while begin != mid:
            if nums[mid] == target:
                return True
            elif nums[mid] > target:
                end = mid
                mid = mean(begin, end)
            else:  # nums[mid] < target
                begin = min(mid + 1, end - 1)
                mid = mean(begin, end)

        return nums[mid] == target


if __name__ == "__main__":
    solution = Solution()
    matrix = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]]
    target = 13
    print(solution.searchMatrix(matrix, target))
