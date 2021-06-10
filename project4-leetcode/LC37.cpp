// LC37.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
    out << "[";
    if (v.size() >= 1) {
        out << v[0];
    }
    for (int i = 1; i < v.size(); i++) {
        out << "," << v[i];
    }
    out << "]" << endl;
    return out;
}

// this helper function checks the validity of position given by (row, column)
// if the char is not present in row, column, and sub-box - return true
bool isValid(int& row, int& column, vector<vector<char>>& board, char& c) {
    for (int i = 0; i < board.size(); i++) {
        if (board[row][i] == c)
            return false;
        if (board[i][column] == c)
            return false;
        if (board[3 * (row / 3) + (i / 3)][3 * (column / 3) + i % 3] == c)
            return false;
    }
    return true;
}

// this function contains the algorithm for solving the sudoku puzzle
bool solve(vector<vector<char>>& board) {
    // traverse the cells of board one by one
    for (int i = 0; i < 9; i++) { 
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') { // cell is empty
                for (char c = '1'; c <= '9'; c++) {
                    // check if any of character is valid at (row, columns)
                    if (isValid(i, j, board, c)) {
                        board[i][j] = c; // place the character
                        if (solve(board)) { // recur to check for other empty positions left
                            return true;
                        }
                        board[i][j] = '.'; // backtrack if that wasn't a valid configuration
                    }
                }
                return false; // return false if none of chars(1-9) can be places
   } } }
    return true; // if the valid configuration was obtained
}

// this function calls solve() to solve the sudoku puzzle
void solveSudoku(vector<vector<char>>& board) {
    if (board.empty()) {
        return;
    }
    solve(board);
}

int main()
{
    vector<vector<char>> board = { {'5','3','.','.','7','.','.','.','.'},
                                   {'6','.','.','1','9','5','.','.','.'},
                                   {'.','9','8','.','.','.','.','6','.'},
                                   {'8','.','.','.','6','.','.','.','3'},
                                   {'4','.','.','8','.','3','.','.','1'},
                                   {'7','.','.','.','2','.','.','.','6'},
                                   {'.','6','.','.','.','.','2','8','.'},
                                   {'.','.','.','4','1','9','.','.','5'},
                                   {'.','.','.','.','8','.','.','7','9'} };
    cout << board << endl;
    solveSudoku(board);
    cout << board;
    
    cout << "\nDone\n";
}
