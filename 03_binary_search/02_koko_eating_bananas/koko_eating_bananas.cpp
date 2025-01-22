#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdint>

using std::vector;

class Solution
{
  public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        auto can_finish = [&](int k) {
            if (k <= 0)
                return false;
            int64_t total_hours = 0;
            for (int pile : piles)
                total_hours += std::ceil((double)pile / k);
            return total_hours <= h;
        };
        int lower = 0;
        int higher = *(std::max_element(piles.begin(), piles.end()));
        int min_k = 1;
        while (lower <= higher)
        {
            int mid = (lower + higher) / 2;
            if (can_finish(mid)) // Try lesser k
            {
                min_k = mid;
                higher = mid - 1;
            }
            else // Try greater k
                lower = mid + 1;
        }
        return min_k;
    }
};

#include <iostream>

int main()
{
    Solution solution;

    vector<int> piles = {3, 6, 7, 11};
    int         h = 8;
    std::cout << solution.minEatingSpeed(piles, h) << "\n";

    piles = {30, 11, 23, 4, 20};
    h = 5;
    std::cout << solution.minEatingSpeed(piles, h) << "\n";

    piles = {30, 11, 23, 4, 20};
    h = 6;
    std::cout << solution.minEatingSpeed(piles, h) << "\n";

    piles = {312884470};
    h = 312884469;
    std::cout << solution.minEatingSpeed(piles, h) << "\n";

    piles = {312884470};
    h = 968709470;
    std::cout << solution.minEatingSpeed(piles, h) << "\n";
}
