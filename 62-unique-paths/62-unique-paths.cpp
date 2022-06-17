class Solution {
public:
    int memo(int m, int n, vector<vector<int>> &dp, int i, int j){
        if(dp[i][j] != -1) return dp[i][j];
        if(i==m-1 and j==n-1)
            return dp[i][j] = 1;
        int r=0,b=0;
        if(i<m-1)
            b = memo(m, n, dp, i+1, j);
        if(j<n-1)
            r = memo(m, n, dp, i, j+1);
        return dp[i][j] = (b+r);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return memo(m,n,dp,0,0);
    }
};