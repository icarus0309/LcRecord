/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */

// @lc code=start
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    //总体思想是：每一轮把能够到达的地方存进来
    //有终归有(有进有出直到找到)，无终归无(队列清空)
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        const int N = grid.size();
        if(grid[0][0] || grid[N-1][N-1])
            return -1;
        
        vector<vector<int>> dire = {{0,-1},{-1,0},{-1,-1},{1,-1},{-1,1},{1,0},{0,1},{1,1}};
        using P = pair<int,int>;

        queue<P> q;         //q是存放每一层的可能的下一个节点，用到q的时候说明已经到下一层了
        q.emplace(0,0);
        grid[0][0] = 2;

        int distance=1;

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto now = q.front();
                q.pop();
                int x = now.first, y = now.second;
                if(x==N-1 && y==N-1) {
                    return distance;
                }

                for(auto& it:dire) {
                    int dx = x+it[0], dy = y+it[1];
                    if(dx<0 || dx>N-1 || dy<0 || dy>N-1 || grid[dx][dy])
                        continue;
                    grid[dx][dy] = 2;
                    q.emplace(dx,dy);                    
                }
            }
            distance++;     //当一层遍历完后，dis自然是需要加一的
        }

        return -1;
    }
};

// @lc code=end




/*
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int N = grid.size();
        if(grid[0][0]==1 || grid[N-1][N-1]==1)
            return -1;
        int step = 0, x=0, y=0, idx=0;
        vector<vector<int>> allNextLoc;
        allNextLoc.push_back(nextLoc(grid,make_pair(0,0)));
        while(allNextLoc.size()!=0) {
            
        }
        return -1;
    }

    vector<int> nextLoc(vector<vector<int>>& grid,pair<int,int>& now,int last=0) {
        //这个函数返回当前节点周围可能存在的路径，0代表自身，1表示左上角，8代表右下角，以此类推
        vector<int> allNextRoad;
        int N = grid.size();
        for(int i=1;i<9;i++) {
            if(i == last)
                continue;
            int x = now.first, y = now.second;
            switch (i) {
                case 1: x -= 1; y -= 1; break;
                case 2: x -= 1; break;
                case 3: x -= 1; y += 1; break;
                case 4: y -= 1; break;
                case 5: y += 1; break;
                case 6: x += 1; y -= 1; break;
                case 7: x += 1; break;
                case 8: x += 1; y += 1; break;
            }
            if(x>=0 && x<N && y>=0 && y<N && grid[x][y]==0)
                allNextRoad.push_back(i);
        }
        return allNextRoad;
    }

*/