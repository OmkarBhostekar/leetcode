class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        vector<vector<int>> ans;
        pair<int,int> p = {in[0][0],in[0][1]};
        for(int i=1;i<in.size();i++){
            if(in[i][0]>=p.first and in[i][0]<=p.second){
                p.second = max(p.second,in[i][1]);
            }else{
                ans.push_back({p.first,p.second});
                p = {in[i][0],in[i][1]};
            }
        }
        ans.push_back({p.first,p.second});
        return ans;
    }
};