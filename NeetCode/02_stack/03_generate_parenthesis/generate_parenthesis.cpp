// Standard: C++11

#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution
{
  public:
    //------------------------------- Functions --------------------------------

    vector<string> generateParenthesis(int n)
    {
        vector<string> solutions;
        total_ = n;
        backtrack(0, 0, solutions);
        return solutions;
    }

  private:
    //------------------------------- Functions --------------------------------

    void backtrack(int open, int close, vector<string>& solutions)
    {
        if (open == close && open == total_)
            solutions.push_back(string(chars_.begin(), chars_.end()));
        vector<char> candidates = getCandidates(open, close);
        for (char candidate : candidates)
        {
            chars_.push_back(candidate);
            backtrack((candidate == '(') ? open + 1 : open,
                      (candidate == ')') ? close + 1 : close, solutions);
            chars_.pop_back();
        }
    }

    vector<char> getCandidates(int open, int close)
    {
        vector<char> candidates;
        if (open < total_)
            candidates.push_back('(');
        if (close < open)
            candidates.push_back(')');
        return candidates;
    }

    //---------------------------------- Data ----------------------------------

    vector<char> chars_;
    int          total_;
};

#include <iostream>

int main()
{
    Solution solution;
    auto     a = solution.generateParenthesis(3);
    for (auto each : a)
        std::cout << each << "\n";
}
