class Solution {
public:
    int getPath(vector<vector<int>>& og,vector<vector<int>>& dp, int i, int j){
        if(i>=0 and j>=0 and og[i][j] == 1) return 0;
        if(i==0 and j==0) return 1;
        if(i<0 or j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int x = getPath(og,dp,i,j-1);
        int y = getPath(og,dp,i-1,j);
        dp[i][j] = x+y;
        return dp[i][j];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        vector<vector<int>> dp(og.size(),vector<int>(og[0].size(),-1));
        return getPath(og,dp,og.size()-1,og[0].size()-1);
    }
};