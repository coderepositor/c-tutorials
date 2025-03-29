#include <iostream>
#include <vector>

#define LEN 9 // LEN represents the size of our sudoku

// the board is passed by reference (&)
bool is_possible(std::vector<std::vector<int>>& board,int row,int col, int val)
{
    // check if the column is valid
    for (int i=0;i<LEN;i++)
    {
        if (board[i][col] == val)
        {
            return false;
        }
    }
    // check if the row is valid
    for (int i=0;i<LEN;i++)
    {
        if (board[row][i] == val)
        {
            return false;
        }
    }
    // check if the 3x3 square is valid
    int startRow = 3*(row/3); //get if it is the 0,1 or 2 3x3 square then *3
    int startCol = 3*(col/3);

    /* alternative way
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    */
   
    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (board[i][j] == val)
            {
                return false;
            }
        }
    }
    // if every test passed
    return true;
}
