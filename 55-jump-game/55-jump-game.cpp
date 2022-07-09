class Solution {
public:
    bool rec(vector<int> &nums,vector<int> &dp, int i, int n){
        if(i >= n-1) return true;
        if(dp[i] != -1) return dp[i];
        for(int j=1;j<=nums[i];j++){
            if(rec(nums,dp,i+j,n))
                return dp[i] = true;
        }
        return dp[i] = false;
    }
    
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return rec(nums, dp, 0, nums.size());
    }
};