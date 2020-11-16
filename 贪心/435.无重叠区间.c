/*
 * @lc app=leetcode.cn id=435 lang=c
 *
 * [435] 无重叠区间
 */

// @lc code=start

int Cmp(const void* a, const void* b){
    int *range1 = *(int **)a;
    int *range2 = *(int **)b;
    if (range1[1] == range2[1]) {
        return range2[0] - range1[0];
    }  else {
        return range1[1] - range2[1];
    }
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    if(intervalsSize<2) return 0;
    qsort(intervals,intervalsSize,sizeof(intervals[0]),Cmp);
    int i = 0, num = 0;
    int temp = intervals[0][1];
    for (i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] < temp) {
            ++num;//必去的当前区间，不影响下一个判断，所以不用修改temp
        } else {
            temp = intervals[i][1];
        }
    }
    return num;

}

// @lc code=end

