class Solution {
public:
    int rec(vector<int>& cost,vector<int>& dp, int i, int n){
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = cost[i]+min(rec(cost,dp,i+1,n),rec(cost,dp,i+2,n));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        rec(cost,dp,0,cost.size());
        return min(dp[0],dp[1]);
    }
};