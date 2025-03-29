/*
1. You can't put the same number twice in a row
2. You can't put the same number twice in a column
3. you can't put the same number twice in the 3x3 subgrid the square belongs to
4. The solution problem is solved using backtracking technique
*/

#include <iostream>
#include <vector>
using namespace std;

#define LEN 9 //represents the size of our sudoku

bool is_possible(vector<vector <int>> & board, int row,int col,int val){
    //check if column is valid
    for(int i=0;i<LEN;i++){
        if(board[i][col]==val){
            return false;
        }
    }
    //check if row is valid
    for(int i=0;i<LEN;i++){
        if(board[row][i]==val){
            return false;
        }
    }

    //check if the 3x3 square is valid
    int startRow = 3*(row/3);
    int startCol = 3*(col/3);

    for (int i=startRow;i<startRow+3;i++){
        for(int j=startCol;j<startCol+3;j++){
            if(board[i][j]==val){
                return false;
            }
        }
    }
    return true;
}

bool solve(vector<vector<int>> &board, int row ,int col){
    if(col == LEN){
        if(row==LEN-1){
            return true; // we have  the last square and add 1 to col (sudoku solved)
        }
        col = 0;
        row++;
    }

    if(board[row][col] !=0)  // already filled , solve for next square
    {
        return solve(board,row,col+1);
    }

    for(int x=1;x<=LEN;x++){
        if(is_possible(board,row,col,x)){
            board[row][col] = x;
            if(solve(board,row,col+1)){
                return true;
            }
        }
        board[row][col] =0; //previous x value didn't work so reset it to 0
    }
    return false; //we are in  a dead end, can't solve the  sudoku with current values
}

void print_board(vector<vector<int>> &board){
    for(int row=0;row<LEN;++row){
        for (int col=0;col<LEN;++col){
            cout<<board[row][col] << " ";
            if((col+1)%3 == 0 && col < LEN-1){
                cout << "| ";
            }        
        }
        cout << endl;
        if((row+1)%3==0 && row < LEN-1){
            cout << "------+------+------" <<endl;
        }
    }
}

int main(){
    vector<vector<int>> sudokuboard ={
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    cout << "Sudoku Grid" << endl;
    print_board(sudokuboard);
    bool solved = solve(sudokuboard,0,0);
    if(solved){
        cout << "Solved Sudoku" <<endl;
        print_board(sudokuboard);
    }
    else{
        cout << "\nNo solution exists"<<endl;
    }
    return 0;
}

