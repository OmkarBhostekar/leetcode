class Solution {
public:
    int mem(vector<vector<int>>& t,vector<vector<int>> &dp,int i, int j){
        if(i==t.size())
            return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int x = t[i][j] + mem(t,dp,i+1,j);
        int y = t[i][j] + mem(t,dp,i+1,j+1);
        return dp[i][j] = min(x,y);
    }
    
    int minimumTotal(vector<vector<int>>& t) {
        vector<vector<int>> dp(t.size(),vector<int>(t.size(),-1));
        return mem(t,dp,0,0);
    }
};