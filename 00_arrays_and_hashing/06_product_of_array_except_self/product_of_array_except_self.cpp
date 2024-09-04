#include <vector>

class Solution
{
  public:
    std::vector<int> productExceptSelf(std::vector<int>& nums)
    {
        int forward[nums.size()];
        int backward[nums.size()];

        forward[0] = 1;
        for (int i = 1; i < nums.size(); ++i)
            forward[i] = forward[i - 1] * nums[i - 1];

        backward[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i >= 0; --i)
            backward[i] = backward[i + 1] * nums[i + 1];

        std::vector<int> ans;
        ans.resize(nums.size());
        for (int i = 0; i < nums.size(); ++i)
            ans[i] = forward[i] * backward[i];

        return ans;
    }

    std::vector<int> productExceptSelf_dynamicProgramming(std::vector<int>& nums)
    {
        int len = nums.size();

        std::vector<int> output(len);
        output[0] = 1;
        for (int i = 1; i < len; ++i)
            output[i] = output[i - 1] * nums[i - 1];

        int right = 1;
        for (int i = len - 1; i >= 0; --i)
        {
            output[i] *= right;
            right *= nums[i];
        }
        return output;
    }
};


#include <iostream>

int main()
{
    Solution solution;
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    std::vector<int> sorted = solution.productExceptSelf(nums);
    for (int i = 0; i < sorted.size(); ++i)
        std::cout << sorted[i] << " ";
    std::cout << "\n";
}
