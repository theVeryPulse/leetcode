#include <string>
#include <array>
#include <iostream>
#include <algorithm> // std::ranges::all_of

class Solution
{
  public:
    bool isAnagram(std::string s, std::string t)
    {
        if (s.size() != t.size())
            return false;
        std::array<int, 26> track = {0};
        for (size_t i = 0; i < s.size(); ++i)
        {
            ++track[s[i] - 'a'];
            --track[t[i] - 'a'];
        }
        return std::ranges::all_of(track, [](int count) { return count == 0; });
    }
};

#include <iostream>

int main()
{
    Solution    solution;
    std::string s("rat");
    std::string t("car");
    std::cout << "Valid anagram: " << solution.isAnagram(s, t) << "\n";
}
