#include <unordered_map>
#include <vector>

// This solution uses hashing (map) to look for the other number's index

class Solution
{
  public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> value_index;
        value_index.reserve(std::ranges::size(nums));
        for (size_t i = 0; i < std::ranges::size(nums); ++i)
        {
            if (value_index.contains(target - nums[i]))
                return {target - nums[i], static_cast<int>(i)};
            else
                value_index[nums[i]] = i;
        }
        return {};
    }
};

#include <iostream>

int main()
{
    Solution         solution;
    std::vector<int> a;
    for (int i = 1; i < 6; ++i)
        a.push_back(i);
    std::vector<int> indexes = solution.twoSum(a, 9);
    if (indexes.size() >= 2)
        std::cout << indexes[0] << " " << indexes[1] << "\n";
}
