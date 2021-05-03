/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    vector<vector<bool>> passed;
    vector<vector<char>> ret;

    void invert(int i, int j, char c)
    {
        int row = i;
        int col = 9 + j;
        int blk = 18 + (i/3)*3 + j/3;
        passed[row][c - '1'] = !passed[row][c - '1'];
        passed[col][c - '1'] = !passed[col][c - '1'];
        passed[blk][c - '1'] = !passed[blk][c - '1'];
    }

    void backTrace(vector<vector<char>>& board, int remain, int i, int j)
    {
        if (remain == 0) {
            ret = board;
            return;
        }
        if (i > 8) {
            return;
        }
        int next_i = i, next_j = j + 1;
        if (j == 8) {
            next_i++;
            next_j = 0;
        }
        if (board[i][j] == '.') {
            for (char c = '1'; c <= '9'; c++) {
                if ((!passed[i][c - '1']) && (!passed[9 + j][c - '1']) && (!passed[18 + (i/3)*3 + j/3][c - '1'])) {
                    board[i][j] = c;
                    invert(i, j, c);
                    backTrace(board, remain - 1, next_i, next_j);
                    invert(i, j, c);
                    board[i][j] = '.';
                }
            }
        } else {
            backTrace(board, remain, next_i, next_j);
        }
    }

    void solveSudoku(vector<vector<char>>& board)
    {    
        passed.assign(27, vector<bool>(9, false)); 
        int remain = 81;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    char c = board[i][j];
                    invert(i, j, c);
                    remain--;
                }
            }
        }
        backTrace(board, remain, 0, 0);
        board = ret;
    }
};

// @lc code=end

