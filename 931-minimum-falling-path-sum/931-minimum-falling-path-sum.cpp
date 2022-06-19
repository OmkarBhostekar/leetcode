class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(),ans = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[m-1] = mat[m-1];
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<n;j++){
                int l=INT_MAX, r=INT_MAX;
                if(j>0) l = dp[i+1][j-1];
                if(j<n-1) r = dp[i+1][j+1];
                dp[i][j] = mat[i][j] + min(dp[i+1][j], min(l,r));
            }
        }
        for(int j=0;j<n;j++)
            ans = min(ans, dp[0][j]);
        return ans;
    }
};