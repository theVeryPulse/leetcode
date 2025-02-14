// HJ85 最长回文子串

#include <string>
#include <iostream>

using namespace std;

bool isPanlindrome(const string& s, size_t start, size_t sub_len)
{
    size_t l = start;
    size_t r = l + sub_len - 1;    
    while (l < r)
    {
        if (s[l] != s[r])
            return false;
        ++l;
        --r;
    }
    return true;
}

int main()
{
    string s;
    getline(cin, s);
    for (size_t sub_len = s.length(); sub_len <= s.length(); --sub_len)
    {
        // 0 1 2 3 4
        // sub_len 3
        // start 0~2
        for (size_t start = 0; start <= s.length() - sub_len; ++start)
        {
            if (isPanlindrome(s, start, sub_len))
            {
                cout << sub_len << endl;
                return 0;
            }
        }
    }
}