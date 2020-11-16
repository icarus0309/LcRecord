/*
 * @lc app=leetcode.cn id=680 lang=c
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start

bool isPalindrome(char *s, int i, int j){
    while(i<j){
        if(*(s+i)!=*(s+j))
            return false;
        i++;
        j--;
    }
    return true;
}

bool validPalindrome(char * s){
    for(int i=0,j=strlen(s)-1;i<j;i++,j--){
        if(*(s+i)!=*(s+j))
            return (isPalindrome(s,i+1,j))||(isPalindrome(s,i,j-1));
    }
    return true;
}


// @lc code=end

