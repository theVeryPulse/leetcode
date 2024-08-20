#include <map>
#include <vector>
#include <cstddef>

// This solution uses hashing (map) to look for the other number's index

class Solution
{
  public:
    typedef std::map<int, int> Map;

    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        Map value_index;
        int size = static_cast<int>(nums.size());
        for (int i = 0; i < size; ++i)
            value_index[nums[i]] = i;

        std::vector<int> solution;
        for (int i = 0; i < size; ++i)
        {
            int           other_number = target - nums[i];
            Map::iterator other_number_iter = value_index.find(other_number);
            if (other_number_iter != value_index.end()
                && other_number_iter->second != i)
            {
                solution.push_back(i);
                solution.push_back(other_number_iter->second);
                break;
            }
        }
        return solution;
    }
};

#include <iostream>

int main()
{
    Solution solution;
    std::vector<int> a;
    for (int i = 1; i < 6; ++i)
        a.push_back(i);
    std::vector<int> indexes = solution.twoSum(a, 9);
    if (indexes.size() >= 2)
        std::cout << indexes[0] << " " << indexes[1] << "\n";
}
