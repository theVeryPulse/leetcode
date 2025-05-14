#include <vector>

using std::vector;

class Solution
{
  public:
    int search(vector<int>& nums, int target)
    {
        size_t begin = 0;
        size_t end = nums.size();
        size_t middle = nums.size() / 2;
        while (begin != middle)
        {
            if (nums[middle] == target)
                return middle;
            else
            {
                if (target > nums[middle])
                    begin = std::min(middle + 1, end - 1);
                else
                    end = middle;
                middle = (begin + end) / 2;
            }
        }
        return (nums[begin] == target) ? begin : -1;
    }
};

#include <iostream>

int main()
{
    Solution solution;
    vector<int> nums = {-1,0,3,5,9,12};
    std::cout << solution.search(nums, 9) << "\n";
    std::cout << solution.search(nums, 2) << "\n";
    std::cout << solution.search(nums, 13) << "\n";
    nums = {-1};
    std::cout << solution.search(nums, 2) << "\n";
}