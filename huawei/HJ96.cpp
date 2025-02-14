// 表示数字

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    cin >> line;
    if (isdigit(line.front()))
        cout << "*";
    for (size_t i = 0; i < line.length(); ++i)
    {
        cout << line[i];
        if (i < line.length() - 1 && (isdigit(line[i]) && !isdigit(line[i + 1]))
            || (!isdigit(line[i]) && isdigit(line[i + 1])))
            cout << "*";
    }
    if (isdigit(line.back()))
        cout << "*";
}