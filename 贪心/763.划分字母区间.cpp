/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int ch[26];
        int i = 0, j = 0, index = 0;
        vector<int> res;
        for(; i<S.length(); i++)
            ch[S[i]-'a'] = i;
        //上面这一步可谓妙极了，直接解决了我想了很久的末位下标问题
        for(i=0; i<S.length(); i++){
            j = max(j,ch[S[i]-'a']);
            if(i == j){
                res.push_back(i-index+1);
                index = i+1;
            }
        }
        return res;
    }
};

// @lc code=end

