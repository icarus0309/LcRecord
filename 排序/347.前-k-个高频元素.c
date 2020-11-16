/*
 * @lc app=leetcode.cn id=347 lang=c
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

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

//教训：不能用数组做，这一题算是失败了
//思路：分为两段，每一段都numsSize长，前一段正常哈希，后一段额外配一个数组extra
//（大小为numsSize）存值
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    
    int* res = (int*)malloc(sizeof(int)*k);
    int i=0, min = nums[0];
    for(;i<numsSize;i++)
        if(nums[i]<min) min = nums[i];

    int* merge = (int*)malloc(sizeof(int)*numsSize*2);
    int* pos   = (int*)malloc(sizeof(int)*numsSize*2);
    int* extra = (int*)malloc(sizeof(int)*numsSize);

    /*初始化*/
    memset(merge,0,sizeof(int)*numsSize*2);
    memset(extra,0,sizeof(int)*numsSize);
    for(i=0; i<numsSize*2; i++)
        pos[i] = i;

    int j=0;    //j用来指定extra以及merge后半段下标
    for(i=0; i<numsSize; i++){
        int now = nums[i]-min;
        if(now <= numsSize){
            merge[now]++;
        }else{
            extra[j] = nums[i];
            merge[j+numsSize]++;
        }
    }
    quickSort(merge, pos, 0, 2*numsSize-1);
    /*输出结果*/
    for(i=0; i<k; i++){
        if(pos[i] <= numsSize){
            res[i] = pos[i]+min;
        }else{
            res[i] = extra[pos[i]-numsSize];
        }
    }
    *returnSize = k;
    return res;
}

// @lc code=end

