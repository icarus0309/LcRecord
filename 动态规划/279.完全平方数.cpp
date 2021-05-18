/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isSquare(int checkNum) {
        int midNum = sqrt(checkNum);
        return midNum * midNum == checkNum;
    }

    int numSquares(int n) {
        int retNumSquaresAddToN = 1;
        if(isSquare(n))
            return retNumSquaresAddToN;
        vector<int> lessThanNSquires;
        int midNum = sqrt(n);
        for(int i = 1; i <= midNum; i++)
            lessThanNSquires.push_back(i * i);
        queue<int> curCheckNumQueue;
        curCheckNumQueue.push(n);
        while(!curCheckNumQueue.empty()) {
            retNumSquaresAddToN++;
            int sizeQue = curCheckNumQueue.size();
            while(sizeQue--) {
                int curNum = curCheckNumQueue.front();
                curCheckNumQueue.pop();
                for(int& i : lessThanNSquires) {
                    int minusCur = curNum - i;
                    if(minusCur < 0) {
                        break;
                    } else if(isSquare(minusCur)) {
                        return retNumSquaresAddToN;
                    }
                    curCheckNumQueue.push(minusCur);
                }
            }
        }
        return retNumSquaresAddToN;
    }
};

// @lc code=end

