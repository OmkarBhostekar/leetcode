class Solution {
public:
    int countOrders(int n) {
        long dp[501];
        dp[1] = 1;
        dp[2] = 6;
        long mod = 1000000007;
        for(int i=3; i<=n; i++){
            int oddNo = 2*i-1;
            int perm = oddNo * (oddNo+1)/2;
            dp[i] = (dp[i-1]*perm)%mod;
        }
        return (int) dp[n];
    }
};