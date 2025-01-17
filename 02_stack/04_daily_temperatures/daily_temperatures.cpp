// Standard: C++11

#include <vector>
#include <stack>

using std::stack;
using std::vector;

class Solution
{
  public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int>   answer(temperatures.size(), 0);
        stack<size_t> to_solve;
        for (size_t i = 0; i < temperatures.size(); i++)
        {
            while (!to_solve.empty()
                   && temperatures[i] > temperatures[to_solve.top()])
            {
                answer[to_solve.top()] = i - to_solve.top();
                to_solve.pop();
            }
            to_solve.push(i);
        }
        return answer;
    }
};

#include <iostream>

template <typename T>
std::ostream& operator<<(std::ostream& os, const vector<T>& vec)
{
    for (const T& each : vec)
        os << each << ", ";
    return os;
}

int main()
{
    vector<int> temps1 = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> temps2 = {80, 34, 80, 80, 80, 34, 34, 34, 34, 34};

    Solution solution;
    auto     answer  = solution.dailyTemperatures(temps1);
    auto     answer2 = solution.dailyTemperatures(temps2);
    std::cout << answer << "\n";
    std::cout << answer2 << "\n";
}
