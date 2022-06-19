class Solution {
public:
    int memo(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j){
        if(i==0 and j==0)
            return dp[i][j] = grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int up=INT_MAX, left=INT_MAX;
        if(i>0) up = memo(grid, dp, i-1, j);
        if(j>0) left = memo(grid, dp, i, j-1);
        return dp[i][j] = grid[i][j] + min(up,left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),-1));
        return memo(grid, dp, grid.size()-1, grid[0].size()-1);
    }
};