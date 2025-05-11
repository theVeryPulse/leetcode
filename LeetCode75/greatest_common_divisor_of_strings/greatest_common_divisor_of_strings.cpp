#include <string>
#include <string_view>

using std::string;

class Solution
{
  public:
    string gcdOfStrings(string str1, string str2) const
    {
        size_t longest{0};
        size_t shorter_len{std::min(str1.length(), str2.length())};
        while (longest < shorter_len && str1[longest] == str2[longest])
            longest++;

        while (longest != 0)
        {
            if (str1.length() % longest == 0 && str2.length() % longest == 0)
            {
                std::string_view sv{std::string_view(str1).substr(0, longest)};
                if (divides(sv, str1) && divides(sv, str2))
                    return string(sv);
            }
            longest--;
        }
        return "";
    }

  private:
    bool divides(std::string_view shorter,
                 std::string_view longer) const noexcept
    {
        auto s_iter{shorter.begin()};
        auto l_iter{longer.begin()};
        while (l_iter != longer.end())
        {
            if (s_iter >= shorter.end())
                s_iter = shorter.begin();
            if (*l_iter != *s_iter)
                return false;
            ++s_iter;
            ++l_iter;
        }
        return s_iter == shorter.end() && l_iter == longer.end();
    }
};

#include <iostream>

int main()
{
    Solution solution;

    string a{"ABABAB"};
    string b{"ABAB"};

    std::cout << solution.gcdOfStrings(a, b) << "\n";
}