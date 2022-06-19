class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        vector<vector<int>> dp(t.size(),vector<int>(t.size(),-1));
        dp[n-1] = t[n-1];

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j] = t[i][j]+ min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};