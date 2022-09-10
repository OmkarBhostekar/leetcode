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
    
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int profit = INT_MIN;
                if(buy){
                    profit = max(-p[i]+dp[i+1][0],0+dp[i+1][1]);
                }else{
                    profit = max(p[i]+dp[i+1][1],0+dp[i+1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};