class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        if(n==1) return dp[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int x = dp[i-1];
            int y = nums[i] + dp[i-2];
            dp[i] = max(x,y);
        }
        return max(dp[n-1],dp[n-2]);
    }
};