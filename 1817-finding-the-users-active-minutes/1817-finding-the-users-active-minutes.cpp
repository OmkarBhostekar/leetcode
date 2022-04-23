class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,unordered_set<int>> mpp;
        for(auto x: logs){
            mpp[x[0]].insert(x[1]);
        }
        vector<int> ans(k);
        for(auto x: mpp){
            if(x.second.size()>0)
                ans[x.second.size()-1]++;
        }
        return ans;
    }
};