#include <string>
#include <ranges>
#include <vector>

using std::string;

class Solution
{
  public:
    string reverseWords(string s)
    {
        int word_begin{static_cast<int>(s.size() - 1)};
        int word_end{static_cast<int>(s.size())};
        string reversed{""};
        while (word_begin >= 0)
        {
            while (word_begin >= 0 && s[word_begin] == ' ')
                --word_begin;
            if (word_begin < 0)
                break;
            word_end = word_begin + 1;

            while (word_begin >= 0 && s[word_begin] != ' ')
                --word_begin;
            ++word_begin;
            
            if (reversed.size() != 0)
                reversed += ' ';
            reversed.append(s, word_begin, word_end - word_begin);
            --word_begin;
        }
        return reversed;
    }
};

#include <iostream>

int main()
{
    Solution solution;

    std::vector<string> strs{"the sky is blue", "a", "a   ", "   a"};

    for (const string& s : strs)
    {
        std::cout << solution.reverseWords(s) << "<\n";
    }
}
