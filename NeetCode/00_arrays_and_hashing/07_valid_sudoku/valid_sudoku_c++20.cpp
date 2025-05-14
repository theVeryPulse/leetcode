#include <vector>
#include <unordered_set>

using std::unordered_set;
using std::vector;

#include <iostream>

class Solution
{
  public:
    /**
     * @brief 
     * 
     * @param board 
     * @return true 
     * @return false 
     */
    bool isValidSudoku(vector<vector<char>>& board)
    {
        // unordered_set<char> check;
        char check[9] = {0};
        // Check rows
        for (const vector<char>& row : board)
        {
            for (const char& value : row)
            {
                if (value == '.') 
                    continue;
                if (check[value - '1']) // if (check.find(value) != check.end())
                    return false;
                else
                    check[value - '1'] = 1; // check.insert(value);
            }
            for (int clear = 0; clear < 9; ++clear) // check.clear();
                check[clear] = 0;
        }

        // Check columns
        for (int i = 0; i < 9; ++i)
        {
            for (const vector<char>& row : board)
            {
                if (row[i] == '.')
                    continue;
                if (check[row[i] - '1']) // if (check.find(row[i]) != check.end())
                    return false;
                else
                    check[row[i] - '1'] = 1; // check.insert(row[i]);
            }
            for (int clear = 0; clear < 9; ++clear) // check.clear();
                check[clear] = 0;
        }

        // Check box
        const int box_count = 3;
        for (int i = 0; i < box_count; ++i)
        {
            for (int j = 0; j < box_count; ++j)
            {
                for (int l = i * 3; l < i * 3 + 3; ++l)
                {
                    for (int m = j * 3; m < j * 3 + 3; ++m)
                    {
                        if (board[l][m] == '.')
                            continue;
                        if (check[board[l][m] - '1']) // if (check.find(board[l][m]) != check.end())
                            return false;
                        else
                            check[board[l][m] - '1'] = 1; // check.insert(board[l][m]);
                    }
                }
                for (int clear = 0; clear < 9; ++clear) // check.clear();
                    check[clear] = 0;
            }
        }
        return true;
    }
};

#include <iostream>

int main()
{
    // vector<vector<char>> board = {
    //     {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    //     {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    //     {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    //     {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    //     {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    //     {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    //     {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    //     {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    //     {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    vector<vector<char>> board = {
        {'.', '.', '.', '.', '.', '.', '5', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'9', '3', '.', '.', '2', '.', '4', '.', '.'},
        {'.', '.', '7', '.', '.', '.', '3', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '3', '4', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '3', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '5', '2', '.', '.'}};

    Solution solution;
    std::cout << solution.isValidSudoku(board) << "\n";
}