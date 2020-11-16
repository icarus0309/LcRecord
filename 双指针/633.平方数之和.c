/*
 * @lc app=leetcode.cn id=633 lang=c
 *
 * [633] 平方数之和
 */

// @lc code=start


bool judgeSquareSum(int c){
    long int a = 0, b = 0;
    for(; b <= sqrt(c); b++){
        if(b*b == c)
            return true;
    }
    b--;
    a++;
    while(a<=b){
        long int res = a*a + b*b;
        if(res == c){
            return true;
        }else if(res < c){
            a++;
        }else{
            b--;
        }
    }
    return false;

}


// @lc code=end

