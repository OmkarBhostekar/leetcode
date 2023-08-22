class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int ec) {
        multiset<int> st;
        for(auto x: c) st.insert(x);
        vector<bool> ans((int)c.size(),false);
        for(int i=0;i<ans.size();i++){
            st.erase(st.lower_bound(c[i]));
            int maxi = *st.rbegin();
            ans[i] = c[i]+ec >= maxi;
            st.insert(c[i]);
        }
        return ans;
    }
};