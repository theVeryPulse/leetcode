#include <vector>

class Solution
{
  public:
    int findMin(std::vector<int>& nums)
    {
        if (nums.front() < nums.back() || nums.size() == 1)
            return nums.front();
        if (nums.size() == 2)
            return std::min(nums[0], nums[1]);

        size_t l = 0;
        size_t r = nums.size() - 1;
        size_t m = avg(l, r);
        while (1)
        {
            if (l + 1 == m && nums[l] > nums[m]) // Minimun is found
                return nums[m];
            else if (m + 1 == r && nums[m] > nums[r])
                return nums[r];

            if (nums[l] < nums[m]) // minimum is to the right of middle
                l = m;
            else // nums[l] > nums[m] // minimu is to the left of middle
                r = m;
            m = avg(l, r);
        }
    }

  private:
    int avg(int a, int b)
    {
        return (a + b) / 2;
    }
};

#include <iostream>

int main()
{
    Solution         solution;
    std::vector<int> a {0, 1, 2};
    std::vector<int> b {2, 0, 1};
    std::vector<int> c {1, 2, 0};
    std::cout << solution.findMin(a) << "\n";
    std::cout << solution.findMin(b) << "\n";
    std::cout << solution.findMin(c) << "\n";
}