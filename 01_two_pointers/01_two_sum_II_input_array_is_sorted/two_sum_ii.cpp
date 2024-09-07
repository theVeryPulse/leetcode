#include <vector>

using std::vector;

class Solution
{
  public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int l = 0;
        int r = numbers.size() - 1;
        while (1)
        {
            int sum = numbers[l] + numbers[r];
            if (sum == target)
            {
                vector<int> answer;
                answer.push_back(l + 1);
                answer.push_back(r + 1);
                return answer;
            }
            else if (sum < target)
                ++l;
            else // sum > target
                --r;
        }
    }
};

#include <iostream>

int main()
{
    vector<int> vec;
    vec.push_back(5);
    vec.push_back(25);
    vec.push_back(75);
    // vec.push_back(5);

    Solution solution;
    vector<int> result = solution.twoSum(vec, 100);
    for (size_t i = 0; i < result.size(); ++i)
    {
        std::cout << result[i] << "\n";
    }
}