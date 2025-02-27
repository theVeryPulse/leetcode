#include <string>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        size_t              first = 0;
        size_t              last = 0;
        int                 longest = 0;
        unordered_set<char> char_track;
        while (last < s.length())
        {
            // Locate and skip to duplicate letter
            while (char_track.contains(s[last]))
            {
                char_track.erase(s[first]);
                ++first;
            }
            char_track.insert(s[last]);
            ++last;
            longest = max(static_cast<int>(last - first), longest);
        }
        return longest;
    }
};

#include <iostream>
#include <assert.h>

int main()
{
    Solution sln;
    string   test {"pwwkew"};
    test = "aab";
    assert(sln.lengthOfLongestSubstring(test) == 2);

    test = "nfpdmpi";
    assert(sln.lengthOfLongestSubstring(test) == 5);

    test = "abc";
    assert(sln.lengthOfLongestSubstring(test) == 3);

    test = "tmmzuxt";
    assert(sln.lengthOfLongestSubstring(test) == 5);
}