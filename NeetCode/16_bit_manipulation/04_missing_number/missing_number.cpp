#include <vector>

using namespace std;

class Solution
{
  public:
    int missingNumber(vector<int>& nums)
    {
        vector<bool> exists(nums.size() + 1, false);
        for (int num : nums)
            exists[num] = true;
        for (int num = 0; num < exists.size(); ++num)
        {
            if (!exists[num])
                return num;
        }
        return -1;
    }
};