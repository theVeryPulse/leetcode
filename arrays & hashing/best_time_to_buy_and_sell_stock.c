// Topics: two pointers, dynamic programming

int maxProfit(int* prices, int pricesSize)
{
    int buy_price;
    int right;
    int max_profit;

    max_profit = 0;
    buy_price = prices[0];
    right = 1;
    while (right < pricesSize)
    {
        if (prices[right] > buy_price)
        {
            if (prices[right] - buy_price > max_profit)
                max_profit = prices[right] - buy_price;
        }
        else
            buy_price = prices[right];
        right++;
    }
    return (max_profit);
}

#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("%d\n" ,maxProfit((int []){2, 1, 2, 0, 1}, 5));
}
