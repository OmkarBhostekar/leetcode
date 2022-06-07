class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        int prev2 = nums[0];
        if(n==1) return prev2;
        int prev = max(prev2,nums[1]);
        for(int i=2;i<n;i++){
            int x = max(prev,nums[i]+prev2);
            prev2 = prev;
            prev = x;
        }
        return max(prev2,prev);
    }
};