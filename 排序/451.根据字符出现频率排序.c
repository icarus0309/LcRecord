/*
 * @lc app=leetcode.cn id=451 lang=c
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start

#define ASCII_MAX_CNT 128

void swap(int* a, int* pos, int i, int j){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
    tmp  = pos[i];
    pos[i] = pos[j];
    pos[j] = tmp;
}

int partition(int* a, int* pos, int l, int r){
    int x=a[r], i=l-1, j=l;
    for(; j<r; j++){
        if(a[j] > x)
            swap(a,pos,++i,j);
    }
    swap(a,pos,++i,r);
    return i;
}

void quickSort(int* a, int *pos, int l, int r){
    if(l<r){
        int k = partition(a,pos,l,r);
        quickSort(a,pos,k+1,r);
        quickSort(a,pos,l,k-1);
    }
}

char * frequencySort(char * s){
    int len = strlen(s);
    if(len==0) return s;
    int i=0;
    int str[ASCII_MAX_CNT] = {0};
    int pos[ASCII_MAX_CNT] = {0};
    for(i=0; i<len; i++)
        str[s[i]]++;
    for(i=0; i<ASCII_MAX_CNT;i++)
        pos[i] = i;
    quickSort(str,pos,0,ASCII_MAX_CNT-1);
    char* res = (char*)malloc(sizeof(char)*(len+1));
    int j = 0;
    for(i=0;str[i]!=0;i++){
        while(str[i]!=0){
            //printf("%d\n", str[i]);
            str[i]--;
            res[j++] = pos[i];
        }
    }
    res[j] = '\0';
    return res;
}

// @lc code=end

