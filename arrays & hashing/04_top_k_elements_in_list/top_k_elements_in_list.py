class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        value_to_count = dict()
        for value in nums:
            if value in value_to_count:
                value_to_count[value] += 1
            else:
                value_to_count[value] = 1

        sorted_values = sorted(value_to_count.items(), key=lambda item: item[1],
                               reverse=True)
        return [value for value, count in sorted_values[:k]]


def test():
    print("Running test...")
    solution = Solution()
    nums = [1, 1, 1, 2, 2, 3]
    k = 2
    ans = solution.topKFrequent(nums, k)
    for num in ans:
        print(num)


if __name__ == "__main__":
    test()
