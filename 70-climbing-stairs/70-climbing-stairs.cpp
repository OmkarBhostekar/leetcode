class Solution {
public:
    int mem(vector<int> &dp, int n){
        if(dp[n])
            return dp[n];
        if(n<=2){
            dp[n] = n;
            return dp[n];
        }
        int x,y;
        if(dp[n-1])
            x = dp[n-1];
        else{
            x = mem(dp,n-1);
            dp[n-1] = x;
        }
        if(dp[n-2])
            y = dp[n-2];
        else{
            y = mem(dp,n-2);
            dp[n-2] = y;
        }
        return x+y;
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1);
        return mem(dp,n);
    }
};