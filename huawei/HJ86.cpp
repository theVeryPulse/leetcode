// HJ85 最长回文子串

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int longest_bit1_len = 0;
    int curr_bit1_len = 0;
    for (int i = 0; i < 32; ++i)
    {
        if ((n & (1 << i)) > 0)
            ++curr_bit1_len;
        else
            curr_bit1_len = 0;
        longest_bit1_len = max(longest_bit1_len, curr_bit1_len);
    }
    cout << longest_bit1_len << endl;
}
