/*
 * @lc app=leetcode.cn id=452 lang=c
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
/*完全错误
int Cmp(const void* a, const void* b){
    int *temp_a = *(int**)a;
    int *temp_b = *(int**)b;
    if(temp_b[1] == temp_a[1]){
        return temp_a[0] > temp_b[0]; //无所谓
    }else{
        return temp_a[1] > temp_b[1];
    }
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize){
    if(pointsSize<2) return pointsSize;
    qsort(points, pointsSize, sizeof(points[0]), Cmp);
    int num = 0;
    num += points[0][1]<points[1][0];
    int r_num = pointsSize-1;
    int l_num = pointsSize-1;
    
    while(r_num>0 && l_num>0){
        int temp = points[l_num][0];
        while(temp<=points[r_num][1] && r_num>0)
            r_num--;
        num++;
        l_num--;
    }

    return num;
}*/

int cmp(const void *a, const void* b){
    int *tmp_a = *(int**)a;
    int *tmp_b = *(int**)b;
    return tmp_a[1] > tmp_b[1];//搞不懂
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize){
    if(pointsSize<2) return pointsSize;
    int num = 1;
    qsort(points,pointsSize,sizeof(points[0]),cmp);//这里即使用指针也没关系。
    int subend = points[0][1];
    for(int i=1; i<pointsSize; i++){
        if(points[i][0] > subend){
            num++;
            subend = points[i][1];
        }
    }
    return num;
}


// @lc code=end

