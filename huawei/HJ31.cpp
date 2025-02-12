// 单词倒排

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string line;
    getline(cin, line);

    vector<string> words;
    size_t         start = 0;
    while (true)
    {
        while (start < line.length() && !isalpha(line[start]))
            ++start;
        if (start == line.length())
            break;
        size_t len = 0;
        while (start + len < line.length() && isalpha(line[start + len]))
            ++len;
        words.push_back(line.substr(start, len));
        start += len;
    }
    for (size_t i = words.size() - 1; i < words.size(); --i)
    {
        cout << words[i];
        if (i != 0)
            cout << " ";
    }
    cout << "\n";
}
