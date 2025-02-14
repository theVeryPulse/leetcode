// HJ91 走方格的方案数

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int total_rows;
    int total_columns;
    cin >> total_rows >> total_columns;
    total_rows++;
    total_columns++;
    vector<vector<int>> matrix(total_rows, vector<int>(total_columns, 1));
    for (int row = 1; row < total_rows; ++row)
    {
        for (int col = 1; col < total_columns; ++col)
            matrix[row][col] = matrix[row - 1][col] + matrix[row][col - 1];
    }
    cout << matrix[total_rows - 1][total_columns - 1] << "\n";
}
