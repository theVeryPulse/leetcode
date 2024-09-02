#include <string>
#include <array>
#include <iostream>

class Solution
{
  public:
    bool isAnagram(std::string s, std::string t)
    {
        if (s.size() != t.size())        
            return false;
        std::array<int, 26> track = {0};
        auto iter_s = s.begin();
        auto iter_t = t.begin();
        while (iter_s != s.end())
        {
            ++(track[*iter_s - 'a']);
            --(track[*iter_t - 'a']);
            ++iter_s;
            ++iter_t;
        }
        for (const auto& count : track)
            if (count != 0)
                return false;
        return true;
    }
};

#include <iostream>

int main()
{
    Solution solution;
    std::string s("rat");
    std::string t("car");
    std::cout << "Valid anagram: " << solution.isAnagram(s, t) << "\n";
}
