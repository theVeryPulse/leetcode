int max(int a, int b)
{
    return (a > b) ? a : b;
}

#define MAX(a, b) ((a > b) ? a : b)

int maxProfit(int* prices, int pricesSize)
{
    int buy = 0;
    int sell = 1;
    int max_profit = 0;
    while (sell < pricesSize)
    {
        if (prices[buy] < prices[sell])
            max_profit = max(max_profit, prices[sell] - prices[buy]);
        else
            buy = sell;
        sell++;
    }
    return max_profit;
}