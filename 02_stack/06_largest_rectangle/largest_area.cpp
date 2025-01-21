#include <vector>
#include <stack>

using std::stack;
using std::vector;

class Solution
{
  public:
    struct IndexHeight
    {
        size_t index_;
        int    height_;

        IndexHeight(size_t index, int height) : index_(index), height_(height)
        {
        }
    };

    int largestRectangleArea(vector<int>& heights)
    {
        int largest_area = 0;

        stack<IndexHeight> index_height;
        for (size_t i = 0; i < heights.size(); ++i)
        {
            size_t leftmost = i;
            while (!index_height.empty()
                   && heights[i] < index_height.top().height_)
            {
                IndexHeight& top = index_height.top();
                int          area = (i - top.index_) * top.height_;
                largest_area = std::max(area, largest_area);
                leftmost = top.index_;
                index_height.pop();
            }
            index_height.push(IndexHeight(leftmost, heights[i]));
        }
        while (!index_height.empty())
        {
            IndexHeight& top = index_height.top();
            int          area = (heights.size() - top.index_) * top.height_;
            largest_area = std::max(area, largest_area);
            index_height.pop();
        }
        return largest_area;
    }
};

#include <iostream>

int main()
{
    Solution    solution;
    vector<int> heights;

    heights = {2, 1, 5, 6, 2, 3};
    std::cout << solution.largestRectangleArea(heights) << "\n";
    heights = {2, 1, 2};
    std::cout << solution.largestRectangleArea(heights) << "\n";
}