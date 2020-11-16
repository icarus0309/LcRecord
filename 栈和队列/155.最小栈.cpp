/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
    int* text;
    int size;
public:
    /** initialize your data structure here. */
    MinStack() {
        text = NULL;
        size = 0;
    }
    
    void push(int x) {
        if(text==NULL) {
            text = new int[1];
            text[0] = x;
            size++;
        } else {
            int* tmp = text;         
            //delete text;
            text = new int[size+1];
            memcpy(text,tmp,size*sizeof(int)); 
            text[size] = x;           
            size++;
        }
        /*
        cout << "当前栈内元素:";
        for(int i=0; i<size; i++) cout << text[i] << " ";
        cout << endl;
        */
        //cout << "size:" << size << endl;
    }
    
    void pop() {        
        if(size==0)
            return;
        if(size==1) {
            text = NULL;
            size=0;
            return;
        }
        int* tmp = text;
        text = (int*)malloc(sizeof(int)*(size-1));
        memcpy(text,tmp,(size-1)*sizeof(int));
        size--;
    }
    
    int top() {
        if(size == 0) return -1;
        return text[size-1];
    }
    
    int getMin() {
        //cout << "size in min:" << size << endl;
        if(size == 0) return -1;
        int minval = text[0];
        for (int i=1;i<size;i++) {
            if (minval > text[i]) {
                minval = text[i];
            }
        }
        //cout << "min_val:" << minval << endl;
        return minval;
    }
};


