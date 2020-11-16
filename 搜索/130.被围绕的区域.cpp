/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start

//深度优先搜索
class Solution {
public:
    void dfs(int x, int y, vector<vector<char>>& board) {
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y]!='O') {
            return;
        }
        board[x][y] = 'A';
        dfs(x-1,y,board);
        dfs(x+1,y,board);
        dfs(x,y+1,board);
        dfs(x,y-1,board);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m==0) {
            return;
        }
        int n = board[0].size();
        for(int i=0; i<m; i++) {
            dfs(i,0,board);
            dfs(i,n-1,board);
        }
        for(int j=1; j<n-1; j++) {
            dfs(0,j,board);
            dfs(m-1,j,board);
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j]=='A') {
                    board[i][j] = 'O';
                } else if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
// @lc code=end

