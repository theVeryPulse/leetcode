class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        num_index = dict()
        for index, num in enumerate(nums):
            if num_index.get(num) is None:
                num_index[num] = [index]
            else:
                num_index[num] += [index]

        for index, num in enumerate(nums):
            if (target - num) in num_index:
                if num * 2 == target and len(num_index[num]) > 1:
                    return [index, num_index[num][1]]
                elif num * 2 != target:
                    return [index, num_index[target - num][0]]


def main():
    solution = Solution()
    numbers = [3, 2, 4]
    two_sum = solution.twoSum(numbers, 6)
    print(two_sum)


if __name__ == "__main__":
    main()
