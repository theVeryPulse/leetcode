// HJ84 统计大写字母个数

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    getline(cin, line);
    int uppers = 0;
    for (char c : line)
    {
        if (isupper(c))
            ++uppers;
    }
    cout << uppers << "\n";
}
