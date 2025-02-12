// 统计字符

#include <string>
#include <iostream>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int alpha = 0;
    int space = 0;
    int digit = 0;
    int other = 0;
    for (char c : s)
    {
        if (isalpha(c))
            ++alpha;
        else if (isspace(c))
            ++space;
        else if (isdigit(c))
            ++digit;
        else
            ++other;
    }
    cout << alpha << "\n" << space << "\n" << digit << "\n" << other << endl;
}
