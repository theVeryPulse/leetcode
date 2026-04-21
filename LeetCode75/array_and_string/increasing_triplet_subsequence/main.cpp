#include <vector>
#include <limits>
#include <iostream>

using std::vector;

class Solution
{
  public:
    bool increasingTriplet(vector<int>& nums)
    {
        int small{std::numeric_limits<int>::max()};
        int mid{small};
        for (int num : nums)
        {
            if (num < small)
                small = num;
            else if (num > small && num < mid)
                mid = num;
            else if (num > mid)
                return true;
        }

        return false;
    }
};

int main(void)
{
    Solution solution;
    vector<int> nums{1,1,-2,6};
    std::cout << solution.increasingTriplet(nums) << "\n";
}