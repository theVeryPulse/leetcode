from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        answer = []
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            j = i + 1
            k = len(nums) - 1
            while (i < j < k):
                sum = nums[i] + nums[j] + nums[k]
                if sum == 0:
                    answer.append([nums[i], nums[j], nums[k]])
                    while j < k and nums[j] == nums[j + 1]:
                        j += 1
                    while k > j and nums[k - 1] == nums[k]:
                        k -= 1
                    j += 1
                    k -= 1
                elif sum > 0:
                    k -= 1
                elif sum < 0:
                    j += 1
        return answer


if __name__ == "__main__":
    solution = Solution()
    nums = [-1, 0, 1, 2, -1, -4]
    answer = solution.threeSum(nums)
    print(answer)
