class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b){
        return a[0]==b[0] ? a[1]<b[1] : a[0]>b[0];
    }
    /*
    //普通解法
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>> res;
        for(auto& a:people){
            res.insert(res.begin()+a[1],a);
        }
        return res;
    }
    */
    //list解法--list相较于vector更加快捷，但牺牲了多一些的空间
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        list<vector<int>> res;
        for(auto& a : people){
            auto pos = res.begin();
            advance(pos,a[1]);
            res.insert(pos,a);
        }
        return vector<vector<int>>(res.begin(),res.end());
    }  
    
};