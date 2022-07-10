class Solution {
public:
    bool rec(vector<int> &nums, int i, int n, vector<int> &dp){
        if(i >= n-1) 
            return true;
        if(dp[i] != -1)
            return dp[i];
        if(nums[i] == 0)
            return false;
        for(int j=1; j<=nums[i]; j++)
            if(rec(nums, i+j, n, dp))
                return dp[i] = true;
        return dp[i] =  false;
    }
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return rec(nums, 0, n, dp);
    }
};