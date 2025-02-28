class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        num_index = dict()
        for index, num in enumerate(nums):
            if (target - num) in num_index:
                return [num_index[target - num], index]
            else:
                num_index[num] = index
        return []


def main():
    solution = Solution()
    numbers = [3, 2, 4]
    two_sum = solution.twoSum(numbers, 6)
    print(two_sum)


if __name__ == "__main__":
    main()
