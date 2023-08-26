class Solution {
public:
    int findLongestChain(vector<vector<int>>& p) {
        sort(p.begin(),p.end());
        int n = p.size();
        // will use one based indexing
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        function<int(int,int)> f = [&](int last, int idx){
            if(idx>n) return 0;
            if(dp[last][idx] != -1) return dp[last][idx];
            int maxi = 0;
            // can pick
            if(last == 0 || p[last-1][1] < p[idx-1][0]){
                maxi = 1+f(idx,idx+1);
            }
            maxi = max(maxi,f(last,idx+1));
            return dp[last][idx] = maxi;
        };
        return f(0,1);
    }
};