#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

class Solution 
{
public:
    //用哈希16ms，不用哈希80ms
    /*返回小于n的平方序列: 1, 4, 9...*/
    vector<int> getSquares(int n, vector<bool>& mpv) {
        vector<int> res; 
        for(int i = 1; i*i <= n; ++i) {
            res.push_back(i*i);
            mpv[i*i] = true;
        }
        return res;
    }

    int numSquares(int n) {
        vector<bool> visited(n+1,false);
        vector<bool> mpv(n+1,false);
        vector<int> squr = getSquares(n,mpv);
        visited[n] = true;
        int size;
        queue<int> q;
        q.push(n);
        int res = 1;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int curr = q.front();
                if(mpv[curr]) return res;
                q.pop();
                for(int num: squr) {
                    int tmp = curr-num;
                    if(tmp<0) break;
                    if(mpv[tmp]) return res;
                    if(visited[tmp]) continue;
                    visited[tmp] = true;
                    q.push(tmp);
                }
            }
            res++;
        }
        return n;
    }
};


/*
//动态规划260ms
class Solution {
public:
    int numSquares(int n) {
        vector<int> res(n+1,0x7FFFFFFF); //这是无符号的最大数字
        res[0] = 0;
        for(int i=0; i<=n; i++) {
            for(int j=1; j*j<=i; j++) {
                res[i] = min(res[i],res[i-j*j]+1);
            }
        }
        return res[n];
    }
};
*/





/*  //暴力穷举，不可取
    //首先需要创建一个数组，为平方数，数值大小范围在1~n^0.5之间
    vector<int> square_nums;

    int giveBackMinSteps(int k) {
        int min_steps = 65535;
        for(int i:square_nums) {
            if(i==k) return 1;
            if(k<i) break;
            int tmp_steps = giveBackMinSteps(k-i)+1;
            min_steps = min(min_steps,tmp_steps);
        }
        return min_steps;
    }

    int numSquares(int n) {
        for(int i=1; i<sqrt(n)+1; i++) { //i必需从1开始
            square_nums.push_back(i*i);
        }
        //存储最小的数目，也就是答案
        return giveBackMinSteps(n);
    }

*/