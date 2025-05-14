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
        for (std::vector<int>::const_iterator iter = nums.begin();
             iter != nums.end(); ++iter)
        {
            if (track.find(*iter) == track.end())
                track.insert(*iter);
            else
                return true;
        }
        return false;
    }
};

#include <iostream>

int main()
{
    int array[] = {1,1,1,3,3,4,3,2,4,2};
    std::vector<int> vec;
    vec.insert(vec.end(), array, array + sizeof(array) / sizeof(array[0]));

    Solution solution;
    std::cout << "Contains duplicate: " << solution.containsDuplicate(vec) 
              << "\n";
}
