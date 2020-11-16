/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size() == 0 ) return false;
        if(n==0) return true;
        if(flowerbed.size()<3){
            if(flowerbed[0]==0 && flowerbed[flowerbed.size()-1]==0 && n<=1)
                return true;
            else return false;
        }
        if(flowerbed[0]==0 && flowerbed[1]==0){
            flowerbed[0]=1;
            n--;
        }
        int i=1;
        for(; i<flowerbed.size()-1; i++){
            if(!flowerbed[i-1]&&!flowerbed[i]&&!flowerbed[i+1]){
                flowerbed[i] = 1;
                n--;
            }
        }
        if(flowerbed[i-1]==0 && flowerbed[i]==0){
            flowerbed[i]=1;
            n--;
        }
        if(n<=0) return true;
        else return false;        
    }
};
// @lc code=end

