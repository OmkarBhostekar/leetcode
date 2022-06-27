class Solution {
public:
    int memo(vector<int> &nums,vector<vector<int>> &dp, int i, int prev, int n){
        if(i>n){
            return 0;
        }
        if(dp[prev][i] != -1) return dp[prev][i];
        int ans = INT_MIN;
        if(prev==0 or nums[prev-1]<nums[i-1]){
            ans = 1 + memo(nums,dp,i+1,i,n);
        }
        ans = max(ans, memo(nums,dp,i+1,prev,n));
        return dp[prev][i] = ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return memo(nums,dp,1,0,n);
    }
};