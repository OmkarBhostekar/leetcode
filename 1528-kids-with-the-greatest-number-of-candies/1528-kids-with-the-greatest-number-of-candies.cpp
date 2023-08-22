class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int ec) {
        int maxi = *max_element(c.begin(),c.end());
        vector<bool> ans((int)c.size(),false);
        for(int i=0;i<ans.size();i++){
            ans[i] = c[i]+ec >= maxi;
        }
        return ans;
    }
};