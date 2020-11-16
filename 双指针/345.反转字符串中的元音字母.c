/*
 * @lc app=leetcode.cn id=345 lang=c
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start

bool judgeVow(char c){
    switch (c)
    {
    case 'a': case 'e': case 'i': case 'o': case 'u':    
    case 'A': case 'E': case 'I': case 'O': case 'U':
        return true;   
    default:
        return false;
    }
}

char * reverseVowels(char * s){
    int len = strlen(s);
    if(len<=1) return s;
    char *phead = s, *ptail = s+len-1;
    int step = 0;
    while(step<len-1){
        if(judgeVow(*phead)&&judgeVow(*ptail)){
            char tmp = *phead;
            *phead = *ptail;
            *ptail = tmp;
            phead++;
            ptail--;
            step += 2;
        }else{
            if(!judgeVow(*phead)){
                phead++;
                step++;
            }
            if(!judgeVow(*ptail)){
                ptail--;
                step++;
            }
        }
    }
    return s;
}


// @lc code=end

