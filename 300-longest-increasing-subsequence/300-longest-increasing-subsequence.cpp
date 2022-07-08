class Solution {
public:
    int rec(vector<int>& nums, int i, int prevIdx ,vector<vector<int>> &dp){
        if(i > nums.size()) return 0;
        if(dp[i][prevIdx] != -1) return dp[i][prevIdx];
        int notTake = rec(nums, i+1, prevIdx, dp);
        int take = INT_MIN;
        if((prevIdx > 0 && nums[i-1] > nums[prevIdx-1]) || prevIdx == 0)
            take = 1 + rec(nums, i+1, i, dp);
        return dp[i][prevIdx] = max(notTake, take);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        rec(nums, 1, 0,dp);
        return dp[1][0];
    }
};