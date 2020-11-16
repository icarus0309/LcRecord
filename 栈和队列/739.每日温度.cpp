/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int,int>> stk;
        vector<int> res(T.size(),0);
        int i=0;
        for(int it : T) {
            pair<int,int> cur(i++,it);
            while(!stk.empty() && cur.second>stk.top().second) {
                res[stk.top().first] = cur.first - stk.top().first;            
                stk.pop();
            }
            stk.push(cur);
        }
        return res;
    }
};
// @lc code=end

/*
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);
        stack<int> stk;
        for (int i = 0; i < T.size(); i ++) {
            while (!stk.empty() && T[i] > T[stk.top()]) {
                res[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};

作者：OrangeMan
链接：https://leetcode-cn.com/problems/daily-temperatures/solution/cjian-ji-dai-ma-dan-diao-zhan-by-orangeman/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

/*
//从这里我吸取到的教训是：cur仅仅只是一个指针，会随着我每轮的赋值而改变
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int*> stk;
        vector<int> res;
        int i=0;
        for(int it : T) {
            res.push_back(0);
            int cur[2];
            cur[0] = i++;
            cur[1] = it;
            //cout << cur[1] << endl;
            if(!stk.empty())
                cout << stk.top()[1]  << endl;
            if(!stk.empty() && cur[1]>stk.top()[1]) {
                //cout << stk.top()[1] << cur[1] << endl;
                res[stk.top()[0]] = cur[1] - stk.top()[1];            
                stk.pop();
            }
            stk.push(cur);
            cout << stk.top()[1] << endl << endl; 
        }
        return res;
    }
*/

