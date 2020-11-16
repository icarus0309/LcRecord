/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
    int islandDFS(int i, int j, vector<vector<int>>& grid) {
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size()) {
            if(grid[i][j]==0) {
                return 0;
            } else {
                grid[i][j] = 0;
                return (1 + islandDFS(i+1,j,grid) + islandDFS(i-1,j,grid) + islandDFS(i,j+1,grid) + islandDFS(i,j-1,grid));
            }
        }
        return 0;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                ans = max(ans,islandDFS(i,j,grid));
            }
        }
        return ans;
    }
};
// @lc code=end

