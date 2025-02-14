// 字符串字符匹配

#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    string s1;
    string s2;
    cin >> s1 >> s2;
    unordered_set<char> s1_chars;
    for (char c : s1)
        s1_chars.emplace(c);
    unordered_set<char> s2_chars;
    for (char c : s2)
        s2_chars.emplace(c);
    for (char c : s1_chars)
    {
        if (s2_chars.find(c) == s2_chars.end())
        {
            cout << "false\n";
            return 0;
        }
    }
    cout << "true\n";
}
