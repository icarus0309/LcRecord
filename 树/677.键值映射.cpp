/*
 * @lc app=leetcode.cn id=677 lang=cpp
 *
 * [677] 键值映射
 */

// @lc code=start
class MapSum {
    struct Node{
        int isEnd_val[2];
        Node* next[26] = {nullptr};
        Node(int flag,int val){
            isEnd_val[0] = flag;
            isEnd_val[1] = val;
        };
    };
    Node* root;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new Node(0,0);
    }
    
    ~MapSum() {
        if(root) delete root;
    }

    void insert(string key, int val) {
        Node* node = root;
        for(char iter:key){
            if(node->next[iter-'a']==nullptr){
                node->next[iter-'a']=new Node(0,val);
                cout << node->next[iter-'a']->isEnd_val[1] << endl;
            }else{
                node->next[iter-'a']->isEnd_val[1]+=val;
                cout << node->next[iter-'a']->isEnd_val[1]<< endl;
            }
            node = node->next[iter-'a'];
        }
        if(node->isEnd_val[0]==0)
            node->isEnd_val[0] = 1;
        else{
            node = root;
            for(char iter:key) {
                node->next[iter-'a']->isEnd_val[1]=val;
                node = node->next[iter-'a'];
            } //再上一次井冈山。。。
        }
    }
    
    int sum(string prefix) {
        Node* node = root;
        for(char iter:prefix){
            if(node->next[iter-'a']==nullptr)
                return 0;
            node = node->next[iter-'a'];
        }
        return node->isEnd_val[1];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end

