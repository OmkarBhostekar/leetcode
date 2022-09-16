class Solution {
public:
    // i = nums left pointer, j = multiplier left pointer
    int rec(vector<int>& nums, vector<int>& m, int i, int j, vector<vector<int>> &dp){
        if(j==m.size()) return 0;
        if(dp[i][j] != INT_MIN) return dp[i][j];
        int left = nums[i]*m[j] + rec(nums,m,i+1,j+1,dp);
        int right = nums[nums.size()-(j-i)-1]*m[j] + rec(nums, m, i, j+1,dp);
        return dp[i][j] = max(left,right);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& m) {
        vector<vector<int>> dp(1000,vector<int>(1000,INT_MIN));
        return rec(nums, m, 0, 0, dp);
    }
};