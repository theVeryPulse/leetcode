#include <vector>
#include <limits>

using std::vector;
using std::size_t;

class Solution
{
  public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        size_t size = nums.size();
        if (size == 0)
            return {};

        vector<int> answer(size, 1);

        // Foward product
        for (size_t i = 1; i < size; ++i)
            answer[i] = nums[i - 1] * answer[i - 1];
        
        // Backward product
        int accumulated = 1;
        for (size_t i = size - 1; i > 0; --i)
        {
            accumulated *= nums[i];
            answer[i - 1] *= accumulated;
        }
        return answer;
    }
};

#include <iostream>

int main()
{
    Solution    solution;
    vector<int> nums = {1,2,3,4};
    auto        answer = solution.productExceptSelf(nums);
    for (const auto& value : answer)
        std::cout << value << "\n";
}