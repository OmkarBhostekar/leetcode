class Solution {
public:
    int MOD = 1e9+7;
    int rec(int i, int j, int mv, int m, int n,vector<vector<vector<int>>> &dp){
        if(i>=m || i<0 || j<0 || j>=n)
            return 1;
        if(dp[i][j][mv] != -1) return dp[i][j][mv];
        if(mv == 0) return 0;
        long long ans = 0;
        ans += rec(i-1,j,mv-1,m,n,dp);
        ans += rec(i+1,j,mv-1,m,n,dp);
        ans += rec(i,j-1,mv-1,m,n,dp);
        ans += rec(i,j+1,mv-1,m,n,dp);
        return dp[i][j][mv] = ans%MOD;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
	    vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return rec(startRow, startColumn, maxMove, m, n, dp);
    }
};