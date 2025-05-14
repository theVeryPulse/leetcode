#include <vector>
#include <cstddef>

class Solution
{
  public:
    int maxArea(std::vector<int>& height)
    {
        size_t l = 0;
        size_t r = height.size() - 1;

        int max_area = 0;
        while (l < r)
        {
            int area = (r - l) * std::min(height[r], height[l]);
            if (area > max_area)
                max_area = area;
            if (height[r] < height[l])
                --r;
            else
                ++l;
        }
        return max_area;
    }
};

#include <iostream>

int main()
{
    int ary[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    std::vector<int> vec;
    for (size_t i = 0; i < sizeof(ary) / sizeof(ary[0]); ++i)
        vec.push_back(ary[i]);

    Solution solution;
    std::cout << solution.maxArea(vec) << "\n";
}
