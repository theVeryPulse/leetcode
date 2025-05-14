#include <vector>
using std::vector;

#include <string>
using std::string;

#include <stack>
using std::stack;

#include <unordered_map>

class Solution
{
  public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> track;

        for (const string& token : tokens)
        {
            if (operations.count(token))
            {
                int b = track.top();
                track.pop();
                int a = track.top();
                track.pop();
                track.push(operations[token](a, b));
            }
            else
                track.push(std::stoi(token));
        }
        return track.top();
    }

  private:
    std::unordered_map<std::string, int (*)(int, int)> operations = {
        {"+", [](int a, int b) { return a + b; }},
        {"-", [](int a, int b) { return a - b; }},
        {"*", [](int a, int b) { return a * b; }},
        {"/", [](int a, int b) { return a / b; }}};
};

#include <iostream>

int main()
{
    vector<string> notations = {"2", "1", "+", "3", "*"};
    Solution       solution;

    int answer = solution.evalRPN(notations);
    std::cout << answer << "\n";
}