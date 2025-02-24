#include <vector>
#include <optional>
//test git
class Solution
{
  public:
    int search(std::vector<int>& nums, int target)
    {
        if (nums.size() == 1)
            return (nums[0] == target) ? 0 : -1;
        if (nums.size() == 2)
        {
            if (nums[0] == target)
                return 0;
            else if (nums[1] == target)
                return 1;
            else
                return -1;
        }
        if (nums.front() < nums.back()) // Already sorted array
            return binarySearch(nums, 0, nums.size(), target);
        int minimum_pos = findMinimumPos(nums);
        if (target < nums[minimum_pos])
            return -1;
        if (target >= nums[0] && target <= nums[minimum_pos - 1])
            return binarySearch(nums, 0, minimum_pos, target);
        else
            return binarySearch(nums, minimum_pos, nums.size(), target);
    }

  private:
    int avg(int a, int b)
    {
        return (a + b) / 2;
    }

    int binarySearch(const std::vector<int>& nums, int begin, int end,
                     int target)
    {
        int middle = avg(begin, end);
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

    int findMinimumPos(const std::vector<int>& nums)
    {
        if (nums.front() < nums.back() || nums.size() == 1)
            return 0;
        if (nums.size() == 2)
            return (nums[0] < nums[1]) ? 0 : 1;

        size_t l = 0;
        size_t r = nums.size() - 1;
        size_t m = avg(l, r);
        while (1)
        {
            if (l + 1 == m && nums[l] > nums[m]) // Minimun is found
                return m;
            else if (m + 1 == r && nums[m] > nums[r])
                return r;

            if (nums[l] < nums[m]) // minimum is to the right of middle
                l = m;
            else // nums[l] > nums[m] // minimu is to the left of middle
                r = m;
            m = avg(l, r);
        }
    }
};

#include <iostream>

int main()
{
    std::vector<int> vec {4, 5, 6, 7, 0, 1, 2};
    // std::vector<int> vec {1, 3};
    int              target {0};

    Solution solution;
    std::cout << solution.search(vec, target) << "\n";
}
