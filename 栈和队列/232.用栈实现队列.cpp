/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
    stack<int> stk;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        //stack<int> stk;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        vector<int> cur;
        while(!stk.empty()) {
            cur.push_back(stk.top());
            stk.pop();
        }
        stk.push(x);
        reverse(cur.begin(),cur.end());
        for(auto& it:cur) {
            stk.push(it);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int cur = stk.top();
        stk.pop();
        return cur;
    }
    
    /** Get the front element. */
    int peek() {
        return stk.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

