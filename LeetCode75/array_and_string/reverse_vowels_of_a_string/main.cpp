#include <string>
#include <unordered_set>

using std::string;

class Solution
{
  public:
    string reverseVowels(string s)
    {
        static const std::unordered_set<char> vowels{'A', 'E', 'I', 'O', 'U',
                                                     'a', 'e', 'i', 'o', 'u'};

        size_t left{0};
        size_t right{s.size() - 1};
        while (left < right)
        {
            while (left < right && !vowels.contains(s[left]))
                ++left;
            while (left < right && !vowels.contains(s[right]))
                --right;
            if (vowels.contains(s[left]) && vowels.contains(s[right]))
                std::swap(s[left], s[right]);
            ++left;
            right = (right == 0) ? 0 : right - 1;
        }
        return s;
    }
};

#include <iostream>

int main()
{
    Solution sln;
    std::cout << sln.reverseVowels("a.");
}