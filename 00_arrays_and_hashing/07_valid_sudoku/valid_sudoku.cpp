#include <vector>
#include <set>
#include <string>

using std::vector;
using std::set;
using std::string;

class Solution
{
  public:
    bool isValidSudoku(vector<vector<char> >& board)
    {
        set<char> track;
        // Check each row
        for (int row = 0; row < 9; ++row)
        {
            for (int column = 0; column < 9; ++column)
            {
                if (board[row][column] == '.')
                    continue;
                if (track.count(board[row][column]))
                    return false;
                else
                    track.insert(board[row][column]);
            }
            track.clear();
        }
        // Check each column
        for (int column = 0; column < 9; ++column)
        {
            for (int row = 0; row < 9; ++row)
            {
                if (board[row][column] == '.')
                    continue;
                if (track.count(board[row][column]))
                    return false;
                else
                    track.insert(board[row][column]);
            }
            track.clear();
        }
        // Check each block
        track.clear();
        for (int block_row = 0; block_row < 3; ++block_row)
        {
            for (int block_col = 0; block_col < 3; ++block_col)
            {
                int row_begin = block_row * 3;
                int row_end   = row_begin + 3;
                int col_begin = block_col * 3;
                int col_end   = col_begin + 3;
                for (int row = row_begin; row < row_end; ++row)
                {
                    for (int col = col_begin; col < col_end; ++col)
                    {
                        if (board[row][col] == '.')
                            continue;
                        if (track.count(board[row][col]))
                            return false;
                        else
                            track.insert(board[row][col]);
                    }
                }
                track.clear();
            }
        }
        return true;
    }
};

#include <iostream>

int main()
{
    vector<vector<char> > board;

    for (int i = 0; i < 9; ++i)
        board.push_back(vector<char>());

    board[0].push_back('.');
    board[0].push_back('.');
    board[0].push_back('.');
    board[0].push_back('.');
    board[0].push_back('5');
    board[0].push_back('.');
    board[0].push_back('.');
    board[0].push_back('1');
    board[0].push_back('.');

    board[1].push_back('.');
    board[1].push_back('4');
    board[1].push_back('.');
    board[1].push_back('3');
    board[1].push_back('.');
    board[1].push_back('.');
    board[1].push_back('.');
    board[1].push_back('.');
    board[1].push_back('.');

    board[2].push_back('.');
    board[2].push_back('.');
    board[2].push_back('.');
    board[2].push_back('.');
    board[2].push_back('.');
    board[2].push_back('3');
    board[2].push_back('.');
    board[2].push_back('.');
    board[2].push_back('1');

    board[3].push_back('.');
    board[3].push_back('8');
    board[3].push_back('.');
    board[3].push_back('.');
    board[3].push_back('.');
    board[3].push_back('.');
    board[3].push_back('.');
    board[3].push_back('2');
    board[3].push_back('.');

    board[4].push_back('.');
    board[4].push_back('.');
    board[4].push_back('2');
    board[4].push_back('.');
    board[4].push_back('7');
    board[4].push_back('.');
    board[4].push_back('.');
    board[4].push_back('.');
    board[4].push_back('.');

    board[5].push_back('.');
    board[5].push_back('1');
    board[5].push_back('5');
    board[5].push_back('.');
    board[5].push_back('.');
    board[5].push_back('.');
    board[5].push_back('.');
    board[5].push_back('.');
    board[5].push_back('.');

    board[6].push_back('.');
    board[6].push_back('.');
    board[6].push_back('.');
    board[6].push_back('.');
    board[6].push_back('.');
    board[6].push_back('2');
    board[6].push_back('.');
    board[6].push_back('.');
    board[6].push_back('.');

    board[7].push_back('.');
    board[7].push_back('2');
    board[7].push_back('.');
    board[7].push_back('9');
    board[7].push_back('.');
    board[7].push_back('.');
    board[7].push_back('.');
    board[7].push_back('.');
    board[7].push_back('.');

    board[8].push_back('.');
    board[8].push_back('.');
    board[8].push_back('4');
    board[8].push_back('.');
    board[8].push_back('.');
    board[8].push_back('.');
    board[8].push_back('.');
    board[8].push_back('.');
    board[8].push_back('.');

    Solution solution;
    std::cout << solution.isValidSudoku(board) << "\n";
}

// 0  [["5",   "3",   ".",   ".",   "7",   ".",   ".",   ".",   "."],
// 1   ["6",   ".",   ".",   "1",   "9",   "5",   ".",   ".",   "."],
// 2   [".",   "9",   "8",   ".",   ".",   ".",   ".",   "6",   "."],
// 3   ["8",   ".",   ".",   ".",   "6",   ".",   ".",   ".",   "3"],
// 4   ["4",   ".",   ".",   "8",   ".",   "3",   ".",   ".",   "1"],
// 5   ["7",   ".",   ".",   ".",   "2",   ".",   ".",   ".",   "6"],
// 6   [".",   "6",   ".",   ".",   ".",   ".",   "2",   "8",   "."],
// 7   [".",   ".",   ".",   "4",   "1",   "9",   ".",   ".",   "5"],
// 8   [".",   ".",   ".",   ".",   "8",   ".",   ".",   "7",   "9"]]

// [   ,   ,   ,   ,"5",   ,   ,"1",   ],
// [   ,"4",   ,"3",   ,   ,   ,   ,   ],
// [   ,   ,   ,   ,   ,"3",   ,   ,"1"],

// ["8",   ,   ,   ,   ,   ,   ,"2",   ],
// [   ,   ,"2",   ,"7",   ,   ,   ,   ],
// [   ,"1","5",   ,   ,   ,   ,   ,   ],

// [   ,   ,   ,   ,   ,"2",   ,   ,   ],
// [   ,"2",   ,"9",   ,   ,   ,   ,   ],
// [   ,   ,"4",   ,   ,   ,   ,   ,   ]