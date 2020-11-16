/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool rankPoints(const vector<int> &a,const vector<int> &b) {
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()<2) return points.size();
        int count = 1;
        //qsort(points, points.size(), sizeof(points[0]), rankPoints);
        sort(points.begin(), points.end(), rankPoints);
        int subend = points[0][1];
        vector<vector<int>>::iterator it;
        for(it = points.begin(); it!=points.end(); it++){
            if( (*it)[0] > subend ){
                count++;
                subend = (*it)[1];
            }
        }
        return count;
    }
};

// @lc code=end

