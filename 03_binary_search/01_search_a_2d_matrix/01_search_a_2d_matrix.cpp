// Standard: C++11

#include <vector>
#include <cstdint>

using std::vector;

class Solution
{
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        auto   mean = [](int a, int b) { return (a + b) / 2; };
        size_t begin = 0;
        size_t end = matrix.size();
        size_t mid = mean(begin, end);
        while (begin != mid)
        {
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] > target)
            {
                end = mid;
                mid = mean(begin, end);
            }
            else // matrix[mid][0] < target
            {
                begin = std::min(mid, end - 1);
                mid = mean(begin, end);
            }
        }

        const auto& vec = matrix[mid];
        begin = 0;
        end = vec.size();
        mid = mean(begin, end);
        while (begin != mid)
        {
            if (vec[mid] == target)
                return true;
            else if (vec[mid] > target)
            {
                end = mid;
                mid = mean(begin, end);
            }
            else // vec[mid] < target
            {
                begin = std::min(mid + 1, end - 1);
                mid = mean(begin, end);
            }
        }
        return vec[mid] == target;
    }
};

#include <iostream>

int main()
{
    vector<vector<int>> matrtix = {
        {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int      target = 13;
    Solution solution;
    std::cout << target << " "
              << ((solution.searchMatrix(matrtix, target)) ? "is " : "is not ")
              << "in matrix.\n";
}
