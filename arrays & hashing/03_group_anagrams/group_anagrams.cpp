#include <vector>
#include <string>
#include <map>

#include <iostream>

typedef std::vector<std::string> StringVec;

class AnagramIdentifier
{
  public:
    AnagramIdentifier()
    {
        for (int i = 0; i < 26; ++i)
            track_[i] = 0;
    }
    AnagramIdentifier(const AnagramIdentifier& other)
    {
        for (int i = 0; i < 26; ++i)
            track_[i] = other.track_[i];
    }
    AnagramIdentifier(const std::string& s)
    {
        for (int i = 0; i < 26; ++i)
            track_[i] = 0;
        for (size_t i = 0; i < s.size(); ++i)
            ++(track_[s[i] - 'a']);
    }

    int track_[26];
};

bool operator<(const AnagramIdentifier& l, const AnagramIdentifier& r)
{
    for (int i = 0; i < 26; ++i)
        if (l.track_[i] != r.track_[i])
            return l.track_[i] < r.track_[i];
    return false;
}

class Solution
{
  public:
    typedef std::map<AnagramIdentifier, int> Map;

    std::vector<StringVec> groupAnagrams(StringVec& strs)
    {
        Map id_to_index;
        int unused_index = 0;

        std::vector<StringVec> solution;

        for (StringVec::const_iterator str = strs.begin(); str != strs.end();
             ++str)
        {
            AnagramIdentifier id(*str);
            if (id_to_index.find(id) == id_to_index.end())
            {
                id_to_index[id] = unused_index++;
                solution.push_back(StringVec());
            }
            solution[id_to_index[id]].push_back(*str);
        }
        return solution;
    }
};

int main()
{
    Solution  solution;
    StringVec strings;

    strings.push_back("eat");
    strings.push_back("tea");
    strings.push_back("tan");
    strings.push_back("ate");
    strings.push_back("nat");
    strings.push_back("bat");

    std::vector<StringVec> grouped_anagrams = solution.groupAnagrams(strings);

    for (std::vector<StringVec>::const_iterator grouped_strings =
             grouped_anagrams.begin();
         grouped_strings != grouped_anagrams.end(); ++grouped_strings)
    {
        for (StringVec::const_iterator string = grouped_strings->begin();
             string != grouped_strings->end(); ++string)
            std::cout << *string << "\n";
        std::cout << "\n";
    }
}
