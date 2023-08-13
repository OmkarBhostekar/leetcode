class Solution {
public:
    bool valid(vector<int>& nums, int i, vector<int> &dp){
        if(dp[i] != -1) return dp[i];
        if(i>=nums.size()) return true;
        if(i==nums.size()-1) return dp[i] = false;
        if(nums[i+1]-nums[i] != 0 && nums[i+1]-nums[i] != 1) return dp[i] = false;
        if(i+1<nums.size() && nums[i] == nums[i+1] && valid(nums,i+2,dp))
            return dp[i] = true;
        if(i+2<nums.size() && nums[i] == nums[i+1] && nums[i+1] == nums[i+2] && valid(nums,i+3,dp))
            return dp[i] = true;
        if(i+2<nums.size() && nums[i+1] - nums[i] == 1 && nums[i+2] - nums[i+1] == 1 && valid(nums,i+3,dp))
            return dp[i] = true;
        return dp[i] = false;
    }
    
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return valid(nums, 0, dp);
    }
};