// 杨辉三角的变形
// 规律: -1 -1 [2 3 2 4] [2 3 2 4] ...
//       1  2  3 4 5 6   7 8 9 10
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int nth_line;
    cin >> nth_line;

    if (nth_line <= 2)
        cout << -1;
    else
    {
        int pattern = (nth_line - 2) % 4;
        if (pattern == 1 || pattern == 3)
            cout << 2;
        else if (pattern == 2)
            cout << 3;
        else if (pattern == 0)
            cout << 4;
    }
    cout << endl;
}

/* 
int main()
{
    int nth_line;
    cin >> nth_line;
    int line_len = nth_line * 2 - 1;
    vector<int> last_line(line_len, 0);
    last_line[line_len / 2] = 1;

    // Determin the line
    for (int i = 0; i < nth_line - 1; ++i)
    {
        vector<int> next_line(line_len, 0);
        for (int index = 0; index < line_len; ++index)
        {
            int value = 0;
            if (index - 1 >= 0)
                value += last_line[index - 1];
            value += last_line[index];
            if (index + 1 < line_len)
                value += last_line[index + 1];
            next_line[index] = value;
        }
        last_line = next_line;
    }
    for (int i = 0; i < last_line.size(); i++)
    {
        if (last_line[i] % 2 == 0)
        {
            cout << i + 1 << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
}
*/
