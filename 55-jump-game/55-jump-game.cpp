class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), last = n-1, i, j;
        for(i=n-2;i>=0;i--)
            if(nums[i]+i>=last) last = i;
        return last<=0;
    }
};