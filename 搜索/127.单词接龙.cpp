/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //代表某个节点已经存在过的，不适合用队列，更不适合用栈，用map的话显得累赘，此时用set最好
        unordered_set<string> s;
        for(auto &i: wordList) {
            s.insert(i); //只要不是multiset就不会重复
        }
        using P = pair<string,int>;
        queue<P> q;
        q.push({beginWord,1});

        while(!q.empty()) {
            P now = q.front();
            q.pop();
            if(now.first == endWord) {
                return now.second;
            }
            for(int i=0; i<now.first.length(); i++) {
                string tmp = now.first;
                for(int j=0; j<26; j++) {
                    char c = 'a'+j;
                    now.first[i] = c;
                    if(s.find(now.first) != s.end()) {
                        q.push({now.first,now.second+1});
                        s.erase(now.first);
                    }
                }
                now.first = tmp;
            }
        } 
        return 0;      
    }
};



// @lc code=end

/*
        //加入所有节点，访问过一次，删除一个。
        unordered_set<string> s;
        for (auto &i : wordList) s.insert(i);

        queue<pair<string, int>> q;
        //加入beginword
        q.push({beginWord, 1});

        string tmp;     //每个节点的字符
        int step;       //抵达该节点的step

        while ( !q.empty() ) {
            if (q.front().first == endWord) {
                return (q.front().second);
            }
            tmp = q.front().first;
            step = q.front().second;
            q.pop();

            //寻找下一个单词了
            char ch;
            for (int i = 0; i < tmp.length(); i++) {
                ch = tmp[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    //从'a'-'z'尝试一次
                    if ( ch == c) continue;
                    tmp[i] = c ;
                    //如果找到的到
                    if ( s.find(tmp) != s.end() ) {
                        q.push({tmp, step+1});
                        s.erase(tmp) ;  //删除该节点
                    }
                    tmp[i] = ch;        //复原
                }
            }

        }
        return 0;
*/

/*

//他比我快的原因在于，他只需要比较26*len次，而且巧妙地将size融入在了pair里，从而省去了一层循环
//而我却需要比较size*(字典长度-已经比较)*len次

class Solution {
public:
    int diffOneChar(string s1, string s2) {
        int len = s1.length();
        int diff=0;
        for(int i=0; i<len; i++) {
            if(s1[i]==s2[i])
                continue;
            diff++;
        }
        return diff;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        int N = wordList.size();
        unordered_set<string> s;
        for(auto& i:wordList) s.insert(i); 
        vector<bool> visited(N);
        int res = 2;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                string now = q.front();
                if(now == endWord) return res;
                q.pop();
                for(int i=0; i<N; i++) {
                    if( !visited[i] ) {
                        if(diffOneChar(wordList[i],now)==1) {
                            if(wordList[i]==endWord)
                                return res;
                            q.push(wordList[i]);
                            visited[i] = true;
                        }
                    }
                }
            }
            res++;
        }
        return 0;
    }
};

*/