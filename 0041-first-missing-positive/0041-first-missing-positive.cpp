class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        unordered_set <int> st;
        for(auto x: v){
            if(x>0) st.insert(x);
        }
        int ans = 1;
        while(st.count(ans)!=0) ans++;
        return ans;
    }
};