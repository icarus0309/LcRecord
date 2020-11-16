/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};

    void dfs(int x, int y, vector<vector<int>>& mat, vector<vector<int>>& rl) {
        rl[x][y] = 1;
        for(auto& d: dir) {
            int dx = d[0] + x;
            int dy = d[1] + y;
            if(dx<0 || dy<0 || dx>mat.size()-1 || dy>mat[0].size()-1 || mat[dx][dy]<mat[x][y] || rl[dx][dy]==1)
                continue;
            dfs(dx,dy,mat,rl);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if( m == 0) return {};
        int n = matrix[0].size();
        vector<vector<int>> r(m,vector<int>(n,0));
        vector<vector<int>> l(r);
        
        for(int i=0; i<m; i++) {
            dfs(i,0,matrix,l);
            dfs(i,n-1,matrix,r);
        }
        for(int j=0; j<n; j++) {    //尤其要注意这里为什么j也要从0开始，因为有两个矩阵，没错，一个矩阵下来肯定能遍历到一些边边角角，但又两个的话，另一个就不一定了，而我们要取的是交集
            dfs(0,j,matrix,l);
            dfs(m-1,j,matrix,r);
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(r[i][j] && l[i][j]) ret.push_back({i,j});
            }
        }    
        
        return ret;
    }
};
// @lc code=end

