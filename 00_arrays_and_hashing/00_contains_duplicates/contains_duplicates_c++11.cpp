/**
 * @brief Given an integer array nums, return true if any value appears at least
 *        twice in the array, and return false if every element is distinct.
 * 
 * @ref   https://leetcode.com/problems/contains-duplicate/description/
 */

#include <vector>
#include <set>

class Solution
{
  public:
    bool containsDuplicate(std::vector<int>& nums)
    {
        std::set<int> track;
        for (const auto& num : nums)
        {
            if (track.find(num) == track.end())
                track.insert(num);
            else
                return true;
        }
        return false;
    }
};

#include <iostream>

int main()
{
    std::vector<int> vec = {1,1,1,3,3,4,3,2,4,2};

    Solution solution;
    std::cout << "Contains duplicate: " << solution.containsDuplicate(vec) 
              << "\n";
}
