#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using std::string;
using std::unordered_map;
using std::vector;

class Solution
{
  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> grouped_anagrams;
        for (const string& str : strs)
        {
            string id = str;
            std::sort(id.begin(), id.end());
            grouped_anagrams[id].emplace_back(str);
        }

        vector<vector<string>> answer;
        answer.reserve(grouped_anagrams.size());
        for (const auto& [id, anagrams] : grouped_anagrams)
            answer.push_back(std::move(anagrams));

        return answer;
    }
};

#include <iostream>

int main()
{
    Solution       solution;
    vector<string> strings = {"eat", "tea", "tan", "ate", "nat", "bat"};

    std::vector<vector<string>> grouped_anagrams = solution.groupAnagrams(
        strings);

    for (std::vector<vector<string>>::const_iterator grouped_strings =
             grouped_anagrams.begin();
         grouped_strings != grouped_anagrams.end(); ++grouped_strings)
    {
        for (vector<string>::const_iterator string = grouped_strings->begin();
             string != grouped_strings->end(); ++string)
            std::cout << *string << "\n";
        std::cout << "\n";
    }
}