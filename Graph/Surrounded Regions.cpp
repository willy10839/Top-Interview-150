/*
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. Such regions are completely enclosed by 'X' cells.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.


Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        for (int i = 0; i < m; i++) {
            helper(board, i, 0);
            helper(board, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            helper(board, 0, j);
            helper(board, m - 1, j);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
    void helper(vector<vector<char>>& board, int i, int j){
        int m = board.size();
        int n = board[0].size();
        if(i<0 || j<0 || i>=m || j >=n || board[i][j]!='O') return;

        board[i][j]='#';
        helper(board,i+1,j);
        helper(board,i-1,j);
        helper(board,i,j+1);
        helper(board,i,j-1);
    }
};