#include <vector>

class Solution
{
  public:
    int maxProfit(std::vector<int>& prices)
    {
        auto buy = prices.begin();
        auto sell = buy + 1;
        int  max_profit = 0;
        while (sell != prices.end())
        {
            if (*buy < *sell)
                max_profit = std::max(*sell - *buy, max_profit);
            else
                buy = sell;
            ++sell;
        }
        return max_profit;
    }
};
