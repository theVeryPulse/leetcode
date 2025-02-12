// 蛇形矩阵

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int lines;
    cin >> lines;
    vector<vector<int>> nums_vec(lines);

    int head_diff = 1;
    int head = 1;
    for (int i = 0; i < lines; ++i)
    {
        nums_vec[i].push_back(head);
        head += head_diff;
        ++head_diff;

        int column_diff = i + 2;
        for (int j = 1; j < lines - i; ++j)
        {
            nums_vec[i].push_back(nums_vec[i][j - 1] + column_diff);
            ++column_diff;
        }
    }
    for (auto& nums : nums_vec)
    {
        for (auto& num : nums)
        {
            cout << num;
            if (num != nums.back())
                cout << " ";
        }
        cout << "\n";
    }
}