#include <string>

using std::string;

class Solution
{
  public:
    string mergeAlternately(string word1, string word2)
    {
        string merged;
        merged.reserve(word1.size() + word2.size());

        string::const_iterator iter1 = word1.begin();
        string::const_iterator iter2 = word2.begin();
        while (iter1 != word1.end() && iter2 != word2.end())
        {
            merged += *iter1;
            merged += *iter2;
            ++iter1;
            ++iter2;
        }
        while (iter1 != word1.end())
        {
            merged += *iter1;
            ++iter1;
        }
        while (iter2 != word2.end())
        {
            merged += *iter2;
            ++iter2;
        }
        return merged;
    }
};

#include <iostream>

int main()
{
    Solution solutoin;
    string   word1 {"abcd"};
    string   word2 {"ABC"};
    std::cout << solutoin.mergeAlternately(word1, word2);
}
