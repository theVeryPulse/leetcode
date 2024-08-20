class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        buy_price = prices[0]
        right = 1
        max_profit = 0

        length = len(prices)
        while right < length:
            if prices[right] > buy_price:
                if prices[right] - buy_price > max_profit:
                    max_profit = prices[right] - buy_price
            else:
                buy_price = prices[right]
            right += 1
        return max_profit


def main():
    solution = Solution()
    print(solution.maxProfit([7, 1, 5, 3, 6, 4]))


if __name__ == '__main__':
    main()
