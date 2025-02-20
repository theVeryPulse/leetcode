// 合唱队

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int total;
    cin >> total;

    vector<int> heights;
    for (int i = 0; i < total; ++i)
    {
        int height;
        cin >> height;
        heights.push_back(height);
    }

    // Find longest line to left of each position
    vector<int> left_longest(total, 0);
    for (int i = 1; i < total; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (heights[i] > heights[j])
                left_longest[i] = max(left_longest[i], left_longest[j] + 1);
        }
    }
    // Find longest line to right of each position
    vector<int> right_longest(total, 0);
    for (int i = total - 2; i >= 0; --i)
    {
        for (int j = total - 1; j >= i; --j)
        {
            if (heights[i] > heights[j])
                right_longest[i] = max(right_longest[i], right_longest[j] + 1);
        }
    }
    // Combine left and right longest lines to find the longest single line
    int longest_line = 0;
    for (int i = 0; i < total; ++i)
    {
        int line_len = left_longest[i] + right_longest[i] + 1;
        longest_line = max(line_len, longest_line);
    }
    cout << total - longest_line << "\n";
}
