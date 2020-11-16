/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
//这一题要小心，虽然最后的结果应该是对的，但是其他位置就不一定了
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(m==0 || n==0)
            return 0;
        vector<vector<int>> sums(m,vector<int>(n));
        sums[0][0] = grid[0][0];
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(i && j) sums[i][j] = grid[i][j] + min(sums[i-1][j],sums[i][j-1]);
                else if(!i && !j) continue;
                else if(!i) sums[i][j] = grid[i][j] + sums[i][j-1];
                else if(!j) sums[i][j] = grid[i][j] + sums[i-1][j];
            }
        }
        return sums[m-1][n-1];
        
       //return sums[0][0];
    } 
};
// @lc code=end

