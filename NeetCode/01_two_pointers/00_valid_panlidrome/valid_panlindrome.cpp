#include <string>

class Solution
{
  public:
    bool isPalindrome(std::string s)
    {
        std::string ready;
        for (std::string::iterator c = s.begin(); c != s.end(); ++c)
        {
            if (isalnum(*c))
                ready.push_back(tolower(*c));
        }
        std::string::const_iterator forward = ready.begin();
        std::string::const_iterator backward = --ready.end();
        while (forward < backward)
        {
            if (*forward != *backward)
                return false;
            ++forward;
            --backward;
        }
        return true;
    }
};

#include <iostream>

int main()
{
    Solution solution;
    std::cout << solution.isPalindrome("0P") << "\n";
}