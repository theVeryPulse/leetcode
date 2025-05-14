#include <vector>
#include <algorithm>

using std::array;
using std::vector;

class Solution
{
  public:
    int longestConsecutive(vector<int>& nums)
    {
        if (nums.size() <= 1)
            return static_cast<int>(nums.size());

        vector<int> sorted = nums;
        std::ranges::sort(sorted);
        auto last = std::unique(sorted.begin(), sorted.end());
        sorted.erase(last, sorted.end());

        int longest = 0;
        int consecutive = 1;
        for (size_t i = 1; i < sorted.size(); ++i)
        {
            if (sorted[i - 1] + 1 == sorted[i])
                ++consecutive;
            else
            {
                longest = std::max(longest, consecutive);
                consecutive = 1;
            }
        }
        return std::max(longest, consecutive);
    }
};

#include <iostream>

int main()
{
    Solution solution;
    // vector<int> nums = {100, 4, 200, 1, 3, 2};
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    std::cout << solution.longestConsecutive(nums) << "\n";
}