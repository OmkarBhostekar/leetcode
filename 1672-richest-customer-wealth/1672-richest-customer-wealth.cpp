class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = INT_MIN;
        for(vector<int> a: accounts){
            m = max(m,accumulate(a.begin(),a.end(),0));
        }
        return m;
    }
};