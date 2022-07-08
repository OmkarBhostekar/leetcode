class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        vector<vector<int>> ans;
        pair<int,int> cur = {in[0][0],in[0][1]};
        for(int i=1;i<in.size();i++){
            if((in[i][0]>=cur.first && in[i][0] <= cur.second) || (in[i][1]>=cur.first && in[i][1] <= cur.second) || (cur.first>=in[i][0] && cur.first <= in[i][1]) || (cur.second>=in[i][0] && cur.second <= in[i][1])){
                cur.first = min(cur.first,in[i][0]);
                cur.second = max(cur.second,in[i][1]);
            }else{
                ans.push_back({cur.first,cur.second});
                cur = {in[i][0],in[i][1]};
            }
        }
        ans.push_back({cur.first,cur.second});
        return ans;
    }
};