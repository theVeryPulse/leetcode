#include <string>

using std::string;

class Solution
{
  public:
    string gcdOfStrings(string str1, string str2)
    {
        if (str1 + str2 != str2 + str1)
            return "";
        size_t big{str1.length()};
        size_t small{str2.length()};
        while (small != 0)
        {
            size_t small_tmp = small;
            small = big % small;
            big = small_tmp;
        }
        return str1.substr(0, big);
    }
};

#include <iostream>

int main()
{
    Solution solution;
    string gcd = solution.gcdOfStrings("ABAB", "ABABAB");
    std::cout << gcd << "\n";
}