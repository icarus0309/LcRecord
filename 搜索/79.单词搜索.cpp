/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void prt(vector<vector<int>> a) {
        for(auto& i : a) {
            for(int j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    bool dfs(pair<int,int> cur_loc, int cur_step, const vector<vector<char>>& board, const string& word, vector<vector<int>>& grid) {
        int cur_x = cur_loc.first, cur_y = cur_loc.second;
        if(cur_x < 0 || cur_y < 0 || cur_x > board.size() - 1 || cur_y > board[0].size() - 1 || \
           board[cur_x][cur_y] != word[cur_step] || \
           grid[cur_x][cur_y] != 0)
            return false;   
        if(cur_step == word.length() - 1)
            return true;
        grid[cur_x][cur_y] = 1;
        bool ret = (dfs({cur_x - 1, cur_y}, cur_step + 1, board, word, grid) || \
                    dfs({cur_x + 1, cur_y}, cur_step + 1, board, word, grid) || \
                    dfs({cur_x, cur_y - 1}, cur_step + 1, board, word, grid) || \
                    dfs({cur_x, cur_y + 1}, cur_step + 1, board, word, grid));
        if(!ret) {
            grid[cur_x][cur_y] = 0;
        }
        // prt(grid);
        return ret;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if(m == 0 || word.length() == 0) return false;
        int n = board[0].size();
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(dfs({i, j}, 0, board, word, grid))
                    return true;
                prt(grid);
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> a = {{'1','2','3','4'},{'2','3','4','5'},{'a','b','c','d'},{'b','c','d','e'}};
    Solution s;
    bool ret = s.exist(a, "b32345d");
    return 0;
}
// @lc code=end

