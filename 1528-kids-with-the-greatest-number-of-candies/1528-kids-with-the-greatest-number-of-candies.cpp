class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int ec) {
        int maxi=0;
        for(int i=0; i<c.size(); i++){
            if(c[i] >= maxi)
                maxi = c[i];
        }
        vector<bool> ans;
        for(int i=0;i<c.size();i++){
            ans.push_back(c[i]+ec >= maxi);
        }
        return ans;
    }
};