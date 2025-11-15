#include <algorithm>
#include <vector>


class Solution
{
  public:
    void moveZeroes(std::vector<int>& nums)
    {
        auto non_zero = nums.begin();
        auto zero = nums.begin();

        while (zero != nums.end() && non_zero != nums.end())
        {
            // Find next zero
            while (zero != nums.end() && *zero != 0)
                ++zero;
            if (zero == nums.end())
                return;

            // Find next non-zero
            while (non_zero != nums.end() && *non_zero == 0)
                ++non_zero;
            if (non_zero == nums.end())
                return;

            if (zero > non_zero)
            {
                non_zero = zero + 1;
                continue;
            }

            std::swap(*zero, *non_zero);
        }
    }
};

#include <iostream>

int main(void)
{
    Solution sol{};

    std::vector<int> nums = {1, 0};
    
    sol.moveZeroes(nums);

    for (size_t i = 0; i < nums.size(); ++i)
        std::cout << nums[i] << "\n";
}