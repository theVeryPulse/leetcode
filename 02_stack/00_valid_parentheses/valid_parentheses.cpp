#include <string>
#include <stack>

using std::string;
using std::stack;

class Solution
{
  public:
    bool isValid(string s)
    {
        stack<char> check;
        for (const char& c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                check.push(c);
            else if (c == ')' || c == ']' || c == '}')
            {
                if (check.size() == 0)
                    return false;
                if (check.top() == '(' && c == ')' ||
                    check.top() == '[' && c == ']' ||
                    check.top() == '{' && c == '}')
                    check.pop();
                else
                    return false;
            }
        }
        return check.size() == 0;
    }
};