/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
public:
    //这个解法收藏吧，也不奢求会了
    vector<int> diffWaysToCompute(string input) {
        int index = 0;
        int num = 0;
        while(index < input.size() && isdigit(input[index]))
            num = num * 10 + input[index++] - '0';
        if(index == input.size()){
            hash[input] = {num};
            return {num};
        }
        vector<int> ans;
        for(int i = 0; i < input.size(); i++){
            if(isOp(input[i])){
                string s1 = input.substr(0,i);
                string s2 = input.substr(i+1); 
                //果然还是得+1啊，不加1不会报错但会影响速度
                vector<int> result1, result2;
                if(!hash.count(s1))
                    result1 = diffWaysToCompute(input.substr(0,i));
                else
                    result1 = hash[s1];
                if(!hash.count(s2))
                    result2 = diffWaysToCompute(input.substr(i+1));
                else
                    result2 = hash[s2];
                for(int r1 : result1){
                    for(int r2 : result2){
                        ans.push_back(calculate(r1,input[i],r2));
                    }
                }
            }
        }
        hash[input] = ans;
        return ans;
    }

    bool isOp(const char& c){
        return c == '+' || c == '-' || c == '*';
    }

    int calculate(const int& num1, const char& op, const int& num2){
        if(op == '+') return num1 + num2;
        else if(op == '-') return num1 - num2;
        else return num1 * num2;
    }
private:
    unordered_map<string,vector<int>> hash;
};
// @lc code=end



/*
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int num = 0;
        int index = 0;
        while(index<input.size() && isdigit(input[index])) {
            num = num*10 + input[index++]-'0';
        }
        if(index==input.size()) return {num};
        vector<int> res;
        for(index=0 ; index<input.size(); index++) {
            if(isOp(input[index])) {
                vector<int> res_1 = diffWaysToCompute(input.substr(0,index));
                vector<int> res_2 = diffWaysToCompute(input.substr(index+1));
                for(auto i:res_1) {
                    for(auto j:res_2) {
                        res.push_back(calculate(i,input[index],j));
                    }
                }
            }
        }
        return res;
    }

    bool isOp(char c) {
        return c=='+'||c=='-'||c=='*';
    }

    int calculate(int a, char op, int b) {
        if(op == '+') return a+b;
        else if(op == '-') return a-b;
        else if(op == '*') return a*b;
        return -1;
    }
};
*/