#include <vector>
#include <algorithm>

class Solution
{
  public:
    int longestConsecutive(std::vector<int>& nums)
    {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return 1;
        std::vector<int> copy(nums);
        std::sort(copy.begin(), copy.end());
        int longest = 1;
        int len = 1;
        for (std::vector<int>::const_iterator num = ++copy.begin();
             num != copy.end(); ++num)
        {
            if (*num == *(num - 1))
                continue;
            if (*num == *(num - 1) + 1)
                ++len;
            else
                len = 1;
            if (len > longest)
                longest = len;
        }
        return longest;
    }
};

#include <iostream>

int main()
{
    Solution solution;
    std::vector<int> vec;
    vec.push_back(0);
    vec.push_back(3);
    vec.push_back(7);
    vec.push_back(2);
    vec.push_back(5);
    vec.push_back(8);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(0);
    vec.push_back(1);
    std::cout << solution.longestConsecutive(vec) << "\n";
}