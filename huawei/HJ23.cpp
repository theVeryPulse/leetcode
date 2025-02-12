// 删除字符串中出现次数最少的字符

#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    string s;
    cin >> s;

    unordered_map<char, int> char_counter_map;
    for (char c : s)
        char_counter_map[c]++;

    int min_occur = numeric_limits<int>::max();
    for (const auto& char_counter : char_counter_map)
    {
        if (char_counter.second < min_occur)
            min_occur = char_counter.second;
    }

    vector<char> bad_chars;
    for (const auto& char_counter : char_counter_map)
    {
        if (char_counter.second == min_occur)
            bad_chars.push_back(char_counter.first);
    }

    string s_new = "";
    for (char c : s)
    {
        if (find(bad_chars.begin(), bad_chars.end(), c) == bad_chars.end())
            s_new += c;
    }

    cout << s_new << endl;
}
