// https://leetcode.com/problems/two-sum/description/

#include <vector>
#include <unordered_map>

class Solution
{
  public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> value_to_indexes;

        int size = static_cast<int>(nums.size());

        for (int i = 0; i < size; ++i)
            value_to_indexes[nums[i]] = i;

        for (int i = 0; i < size - 1; ++i)
        {
            const auto other = value_to_indexes.find(target - nums[i]);
            if (other != value_to_indexes.end())
            {
                if (other->first != nums[i])
                    return std::vector{i, other->second};
                else if (other->second != i)
                    return std::vector{i, other->second};
            }
        }
        return {};
    }
};

#include <iostream>

int main()
{
    Solution         solution;
    std::vector<int> a = {3, 2, 4};
    int              target = 6;

    for (int i = 0; i < 10000; ++i)
        std::vector<int> indexes = solution.twoSum(a, target);
    // for (const int& index : indexes)
    //     std::cout << index << "\n";
}
