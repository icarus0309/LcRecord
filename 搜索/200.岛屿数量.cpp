/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    //做这类题目，要注意核心要求的东西是啥，该加一的就int，该总体的就void
    void islandsDFS(int i, int j, vector<vector<char>>& grid) {
        int cur_n = grid.size();
        int cur_m = grid[0].size();
        grid[i][j] = '0';
        if(i>0 && grid[i-1][j]=='1')        islandsDFS(i-1,j,grid);
        if(i<cur_n-1 && grid[i+1][j]=='1')  islandsDFS(i+1,j,grid);
        if(j>0 && grid[i][j-1]=='1')        islandsDFS(i,j-1,grid);
        if(j<cur_m-1 && grid[i][j+1]=='1')  islandsDFS(i,j+1,grid);
    }
    //思路很简单：逐一打通任督二脉
    int numIslands(vector<vector<char>>& grid) {
        int ret=0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    ret++;
                    islandsDFS(i, j, grid);
                }
            }
        }
        return ret;
    }
};
// @lc code=end

