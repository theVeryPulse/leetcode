class Solution
{
  public:
    int climbStairs(int n)
    {
        if (n == 1 || n == 0)
            return 1;
        int prev = 1;
        int curr = 2;
        int temp;
        for (int i = 2; i < n; ++i)
        {
            temp = curr;
            curr += prev;
            prev = temp;
        }
        return curr;
    }
};

#include <iostream>

int main()
{
    Solution solution;
    std::cout << solution.climbStairs(44) << "\n";
}

/* 

0 -> 1 
1 -> 1
2 -> 2
3 -> 3
4 -> 5
5 -> 8
6 ->


*/
