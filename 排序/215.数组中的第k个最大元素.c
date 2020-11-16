/*
 * @lc app=leetcode.cn id=215 lang=c
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start



void swap(int* a, int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

int partition(int* a, int l, int r){
    /*
    int x=a[r], i=l-1, j=l;
    for(; j<r; j++){
        if(a[j] < x)
            swap(a, ++i, j);
    }
    swap(a, ++i, r);
    return i;
    */
    int i = l, j = r + 1;
    while (true) {
        while (a[++i] < a[l] && i < r) ;
        while (a[--j] > a[l] && j > l) ;
        if (i >= j)
            break;
        swap(a, i, j);
    }
    swap(a, l, j);
    return j;
    
}

int findKthLargest(int* nums, int numsSize, int k){
    k = numsSize - k;
    int l=0, r=numsSize-1;
    while(l<r){
        int index = partition(nums,l,r);
        if(index == k) break;
        else if(index < k) l=index+1;
        else if(index > k) r=index-1;
    }
    return nums[k];
}

// @lc code=end

