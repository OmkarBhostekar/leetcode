class Solution {
public:
    int memo(vector<vector<int>>& mat, vector<vector<int>>& dp, int i, int j){
        if(i==dp.size()-1) return dp[i][j] = mat[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int l=INT_MAX,d=INT_MAX,r=INT_MAX;
        d = memo(mat, dp, i+1, j);
        if(j>0) l = memo(mat, dp, i+1, j-1);
        if(j<mat[0].size()-1) r = memo(mat, dp, i+1, j+1);
        return dp[i][j] = (mat[i][j]+min(l,min(d,r)));
    }

    int minFallingPathSum(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(),ans = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int j=0;j<n;j++){
            ans = min(ans,memo(mat, dp, 0, j));
        }
        return ans;
    }
};