from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l = 0
        r = len(numbers) - 1
        while (True):
            sum = numbers[l] + numbers[r]
            if (sum == target):
                return [l+1, r+1]
            elif ((sum < target)):
                l += 1
            else:
                r -= 1


def test():
    solution = Solution()
    result = solution.twoSum([5, 25, 75], 100)
    print(result)


if __name__ == "__main__":
    test()
        