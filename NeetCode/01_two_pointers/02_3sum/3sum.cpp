#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
  public:
    vector<vector<int> > threeSum(vector<int>& nums)
    {
        vector<vector<int> > solution;
        std::sort(nums.begin(), nums.end());

        size_t i = 0;
        while (i < nums.size() - 2)
        {
            if (i > 0 && nums[i - 1] == nums[i]) // skip checked duplicates
            {
                ++i;
                continue;
            }
            size_t j = i + 1;
            size_t k = nums.size() - 1;
            while (i < j && j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    solution.push_back(vector<int>());
                    solution.back().push_back(nums[i]);
                    solution.back().push_back(nums[j]);
                    solution.back().push_back(nums[k]);
                    while (j < k && nums[j + 1] == nums[j]) // skip duplicates
                        ++j;
                    while (k > j && nums[k - 1] == nums[k]) // skip duplicates
                        --k;
                    ++j;
                    --k;
                }
                else if (sum > 0)
                    --k;
                else if (sum < 0)
                    ++j;
            }
            ++i;
        }
        return solution;
    }
};

int main()
{
    Solution solution;

    vector<int> vec;
    vec.push_back(-1);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(-1);
    vec.push_back(-4);
    // [-1,0,1,2,-1,-4]
    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);
    vector<vector<int> > answer = solution.threeSum(vec);
}
