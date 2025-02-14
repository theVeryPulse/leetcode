#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool asciiCompare(const pair<char, int>& a, const pair<char, int>& b)
{
    return a.first > b.first;
}

bool charFreqCompare(const pair<char, int>& a, const pair<char, int>& b)
{
    return a.second < b.second;
}

int main()
{
    string line;
    cin >> line;
    unordered_map<char, int> char_freq_map;
    for (char c : line)
    {
        char_freq_map[c]++;
    }
    vector<pair<char, int>> char_freq_vector;
    for (const auto& char_freq : char_freq_map)
    {
        char_freq_vector.push_back(char_freq);
    }
    stable_sort(char_freq_vector.begin(), char_freq_vector.end(),
                asciiCompare);
    stable_sort(char_freq_vector.begin(), char_freq_vector.end(),
                charFreqCompare);
    for (auto char_freq = char_freq_vector.rbegin();
         char_freq != char_freq_vector.rend(); ++char_freq)
        cout << char_freq->first;
}
