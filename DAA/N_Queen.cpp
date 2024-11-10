#include <iostream>
#include <vector>

using namespace std;

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(vector<vector<int>> &board, int row, int col, int N)
{
    // Check this column on the upper side
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check the upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check the upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Recursive utility function to solve N-Queens problem
bool solveNQueensUtil(vector<vector<int>> &board, int row, int N, int row0, int col0)
{
    // If all queens are placed, return true
    if (row == N)
        return true;

    // If the current row is the one with the first queen, skip placing a queen
    if (row == row0)
    {
        // Check if the queen at (row0, col0) is safe
        if (!isSafe(board, row0, col0, N))
            return false;
        // Proceed to the next row
        return solveNQueensUtil(board, row + 1, N, row0, col0);
    }

    // Try placing a queen in all columns one by one
    for (int col = 0; col < N; col++)
    {
        // Check if placing a queen at board[row][col] is safe
        if (isSafe(board, row, col, N))
        {
            // Place the queen
            board[row][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQueensUtil(board, row + 1, N, row0, col0))
                return true;

            // If placing queen at board[row][col] doesn't lead to a solution,
            // then backtrack
            board[row][col] = 0;
        }
    }

    // If the queen cannot be placed in any column in this row, return false
    return false;
}

// Function to solve the N-Queens problem with the first queen placed at (row0, col0)
bool solveNQueens(int N, int row0, int col0)
{
    vector<vector<int>> board(N, vector<int>(N, 0));
    board[row0][col0] = 1; // Place the first queen

    if (solveNQueensUtil(board, 0, N, row0, col0))
    {
        // Print the solution
        cout << "Solution:\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        return true;
    }
    else
    {
        // If no solution exists
        cout << "No solution exists with the first queen at the specified position.\n";
        return false;
    }
}

int main()
{
    int N, row0, col0;
    cout << "Enter the size of the board (N): ";
    cin >> N;
    cout << "Enter the position of the first queen (row and column, zero-indexed): ";
    cin >> row0 >> col0;

    if (row0 < 0 || row0 >= N || col0 < 0 || col0 >= N)
    {
        cout << "Invalid position for the first queen.\n";
        return 0;
    }

    solveNQueens(N, row0, col0);

    return 0;
}
