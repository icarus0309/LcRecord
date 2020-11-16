/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int& num : num_set) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;  
    }
};
// @lc code=end


/*
//上面是我一样的逻辑，关键在于那一步if，这是O(N)的关键，否则就是O(N^2)
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int& num : num_set) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;           
    
*/

/*
        map<int,int> mp;
        for(int i:nums) {
            mp[i]++;
        }
        int res = 0;
        map<int,int>::iterator it;
        for(it = mp.begin(); it!=mp.end(); it++) {
            if(!mp.count(it->first-1)) {
                int tmp = 1;
                auto pa = it;
                while(mp.count(pa->first+1)) {
                    tmp++;
                    pa++;
                }
                res = max(res,tmp);
            }
        }
        return res;
*/

