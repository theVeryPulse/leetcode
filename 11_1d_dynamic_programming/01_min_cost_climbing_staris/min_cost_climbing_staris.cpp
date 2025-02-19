#include <vector>

using namespace std;

class Solution
{
  public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        vector<int> min_cost(cost.size() + 1, 0);
        for (int i = 2; i < min_cost.size(); ++i)
        {
            min_cost[i] = min(cost[i - 1] + min_cost[i - 1],
                              cost[i - 2] + min_cost[i - 2]);
        }
        return min_cost.back();
    }
};