#include <vector>
#include <cstddef>

using std::vector;

class Solution
{
  public:
    int trap(vector<int>& height)
    {
        size_t l = 0;
        size_t r = height.size() - 1;

        int l_max = 0;
        int r_max = 0;

        int volumn = 0;
        while (l <= r)
        {
            if (l_max <= r_max)
            {
                int this_column = std::min(l_max, r_max) - height[l];
                if (this_column > 0)
                    volumn += this_column;
                if (height[l] > l_max)
                    l_max = height[l];
                ++l;
            }
            else
            {
                int this_column = std::min(l_max, r_max) - height[r];
                if (this_column > 0)
                    volumn += this_column;
                if (height[r] > r_max)
                    r_max = height[r];
                --r;
            }
        }
        return volumn;
    }
};

int main()
{
    // int ary[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int ary[] = {4, 2, 3};

    std::vector<int> vec;
    for (size_t i = 0; i < sizeof(ary) / sizeof(ary[0]); ++i)
        vec.push_back(ary[i]);

    Solution solution;
    solution.trap(vec);
}