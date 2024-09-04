from typing import List 

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        forward = [1] * len(nums)
        forward[1] = nums[0]
        i = 2
        while (i < len(nums)):
            forward[i] = forward[i-1] * nums[i-1]
            i += 1
        # print(forward)

        backward = [1] * len(nums)        
        backward[-2] = nums[-1]
        i = len(backward) - 3
        while (i >= 0):
            backward[i] = backward[i+1] * nums[i+1]
            i -= 1
        # print(backward)

        ans = [0] * len(nums)
        i = 0
        while (i < len(ans)):
            ans[i] = forward[i] * backward[i]
            i += 1
        # print(ans)
        return ans


def test():
    solution = Solution()
    # solution.productExceptSelf([1, 2, 3, 4, 5, 6])
    # solution.productExceptSelf([1, 2, 3, 4])
    solution.productExceptSelf([-1, 1, 0, -3, 3])


if __name__ == "__main__":
    test()
