/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */

// @lc code=start
class Solution {
public:
    void dfs(int i, int m, vector<vector<int>>& M) {
        M[i][i] = 0;
        for(int j=0; j<m; j++) {
            if(M[i][j] == 1) {
                M[i][j] = 0;
                dfs(j, m, M);
            }
        } 
    }

    int findCircleNum(vector<vector<int>>& M) {
        int m = M.size();
        int ret = 0;
        for(int i=0; i<m; i++) {
            if(M[i][i] == 1) {
                ret++;
                dfs(i,m,M);                
            }
        }
        return ret;
    }

};
// @lc code=end

