class Solution {
public:
    int f(vector<int>& p, int i, int buy, int k, vector<vector<vector<int>>> &dp){
        if(i==p.size()) return 0;
        if(k==0) return 0;
        if(dp[i][buy][k] != -1) return dp[i][buy][k];
        int profit = INT_MIN;
        if(buy){
            profit = max(-p[i]+f(p,i+1,0,k,dp),0+f(p,i+1,1,k,dp));
        }else{
            profit = max(p[i]+f(p,i+1,1,k-1,dp),0+f(p,i+1,0,k,dp));
        }
        return dp[i][buy][k] = profit;
    }
    
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(p,0,1,k,dp);
    }
};