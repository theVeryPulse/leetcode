#include <string>
#include <array>
#include <iostream>
#include <algorithm> // std::ranges::all_of, std::ranges::for_each

class Solution
{
  public:
    bool isAnagram(std::string s, std::string t)
    {
        if (s.size() != t.size())
            return false;
        std::array<int, 26> track {};
        std::ranges::for_each(track, [&](int c) { ++track[c - 'a']; });
        std::ranges::for_each(track, [&](int c) { --track[c - 'a']; });
        return std::ranges::all_of(track, [](int sum) { return sum == 0; });
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
