class Solution {
public:
    int f(vector<int>& p, int i, int buy, vector<vector<int>> &dp){
        if(i==p.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = INT_MIN;
        if(buy){
            profit = max(-p[i]+f(p,i+1,0,dp),0+f(p,i+1,1,dp));
        }else{
            profit = max(p[i]+f(p,i+1,1,dp),0+f(p,i+1,0,dp));
        }
        return dp[i][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        return f(prices,0,1,dp);
    }
};