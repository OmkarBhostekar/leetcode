class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        bool isModified = false;
        for(int i=0;i<n-1;i++){
            if(nums[i] <= nums[i+1])
                continue;
            if(isModified) return false;
            if(i==0 or nums[i+1] >= nums[i-1])
                nums[i] = nums[i+1];
            else
                nums[i+1] = nums[i];
            isModified = true;
        }
        return true;
    }
};