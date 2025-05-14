class Solution
{
  public:
    int climbStairs(int n)
    {
        int prev = 1;
        int curr = 1;
        for (int i = 0; i < n - 1; ++i)
        {
            int next = prev + curr;
            prev = curr;
            curr = next;;
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
