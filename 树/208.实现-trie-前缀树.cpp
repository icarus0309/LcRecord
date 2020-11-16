/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start

struct Node{
    bool isEnd;
    Node* next[26] = {NULL}; //这里一定要提前定义好啊
    Node(bool flag){isEnd = flag;};
};

class Trie {
private:
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node(false);
    }

    ~Trie() {
        if(root) delete root;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for(char iter:word) {
            if(node->next[iter-'a'] == NULL)
                node->next[iter-'a'] = new Node(false);
            node = node->next[iter - 'a'];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for(char iter:word) {
            if(node->next[iter-'a'] == NULL) 
                return false;
            node = node->next[iter-'a'];
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;
        for(char iter:prefix) {
            if(node->next[iter-'a']==NULL) 
                return false;
            node = node->next[iter-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

