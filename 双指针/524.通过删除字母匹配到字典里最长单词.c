/*
 * @lc app=leetcode.cn id=524 lang=c
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start

char * findLongestWord(char * s, char **d, int dSize){
    if(s[0]=='\0') return s;
    char a[1] = "";
    char* res = a;
    for(int i=0; i<dSize; i++){
        char *pd_h = *(d+i), *pd_t = *(d+i)+strlen(*(d+i));
        char *ps_h = s, *ps_t = s+strlen(s);//我冒个险，指向一个未知的地址试试看
        while(pd_h!=pd_t){
            if(*pd_h == *ps_h){
                pd_h++;
                ps_h++;
            }else ps_h++;
            if(ps_h == ps_t)
                break;
        }
        if(pd_h == pd_t){
            int a = strlen(res), b = strlen(*(d+i));
            if(a < b) res = *(d+i);
            else if(a == b){
                if(strcmp(res,*(d+i))==1) res = *(d+i);
                //strcmp的结果为1，说明前者比后者的字典顺序大，0为相等，-1为小
            }
        }
    }
    return res;
}

// @lc code=end

