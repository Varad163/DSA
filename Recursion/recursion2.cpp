#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col, int N)
{
    // Check the column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }

    // Check the upper-left diagonal//./
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueens(vector<vector<int>> &board, int row, int N)
{
    if (row == N)
    { // All queens placed
        for (const auto &r : board)
        {
            for (int cell : r)
                cout << (cell ? "Q " : ". ");
            cout << endl;
        }
        cout << "-----------------\n";
        return true; // Change to `false` to find all solutions
    }

    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col, N))
        {
            board[row][col] = 1;
            if (solveNQueens(board, row + 1, N))
                return true;     // Place next queen
            board[row][col] = 0; // Backtrack
        }
    }

    return false;
}

int main()
{
    int N = 8; // Change this for different board sizes
    vector<vector<int>> board(N, vector<int>(N, 0));
    if (!solveNQueens(board, 0, N))
    {
        cout << "No solution exists.\n";
    }
    return 0;
}
