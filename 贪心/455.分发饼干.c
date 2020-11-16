/*
 * @lc app=leetcode.cn id=455 lang=c
 *
 * [455] 分发饼干
 */

// @lc code=start


void swap(int* a, int i, int j){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

int partition(int* a, int l, int r){
    int x=a[r], i=l-1, j=l;
    for(; j<r; j++){
        if(a[j] < x)
            swap(a,++i,j);
    }
    swap(a,++i,r);
    return i;
}

void quickSort(int* a, int l, int r){
    if(l<r){
        int k = partition(a,l,r);
        quickSort(a,k+1,r);
        quickSort(a,l,k-1);
    }
}
//速度
int findContentChildren(int* g, int gSize, int* s, int sSize){
    if(g==NULL||s==NULL) return 0;
    quickSort(g, 0, gSize-1);
    quickSort(s, 0, sSize-1);
    int gi = 0, si = 0;
    while (gi < gSize && si < sSize) {
        if (g[gi] <= s[si])
            gi++;
        si++;
    }
    return gi;
}


// @lc code=end

