#include <vector>

using std::vector;

class Solution
{
  public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        if (flowerbed.size() == 1)
            return ((flowerbed[0] == 0) ? 1 : 0) >= n;

        int    total{0};
        size_t i{0};
        while (i < flowerbed.size())
        {
            if (i == 0)
            {
                if (flowerbed[i] == 0 && flowerbed[i + 1] == 0)
                {
                    total++;
                    i++;
                }
            }
            else if (i == flowerbed.size() - 1)
            {
                if (flowerbed[i] == 0 && flowerbed[i - 1] == 0)
                {
                    total++;
                    i++;
                }
            }
            else if (flowerbed[i - 1] == 0 && flowerbed[i] == 0
                     && flowerbed[i + 1] == 0)
            {
                total++;
                i++;
            }
            ++i;
        }
        return n <= total;
    }
};

#include <iostream>

int main()
{
    vector<int> flowerbed{1, 0, 0, 0, 1};
    Solution    solution;
    std::cout << solution.canPlaceFlowers(flowerbed, 2) << "\n";
}