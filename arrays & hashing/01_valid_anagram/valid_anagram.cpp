#include <string>

class Solution
{
  public:
    bool isAnagram(std::string s, std::string t)
    {
        if (s.size() != t.size())        
            return false;
        unsigned int track[26];
        std::string::const_iterator iter_s = s.begin();
        std::string::const_iterator iter_t = t.begin();
        while (iter_s != s.end())
        {
            ++(track[*iter_s - 'a']);
            --(track[*iter_t - 'a']);
            ++iter_s;
            ++iter_t;
        }
        for (char i = 0; i < 26; ++i)
            if (track[i] != 0)
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
