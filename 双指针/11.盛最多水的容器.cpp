/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start

//卧槽。。。给if不加{}影响这么大的吗。。。。
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int maxarea = 0;
        while(l<r){
            if(min(height[l],height[r])*(r-l) > maxarea){
                maxarea = min(height[l],height[r])*(r-l);
            }
            if(height[l]>height[r]){
                r--;
            }
            else l++;
        }
        return maxarea;
    }
};

// @lc code=end

