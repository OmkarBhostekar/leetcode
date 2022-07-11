class Solution {
public:
    bool rec(vector<int>& nums,vector<vector<int>>& dp, int total, int sum, int i){
        if(i>=nums.size()){
            return sum == (total-sum);
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        if(rec(nums,dp,total,sum+nums[i],i+1))
            return dp[i][sum] = true;
        return dp[i][sum] = rec(nums, dp,total,sum,i+1);
    }
    
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(nums.size(),vector<int>(total+1,-1));
        return rec(nums, dp, total, 0, 0);
    }
};