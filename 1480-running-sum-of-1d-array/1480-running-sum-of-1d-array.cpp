class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size()/2;i++){
            sum += nums[i];
            nums[i] = sum;
        }
        for(int i=nums.size()/2;i<nums.size();i++){
            sum += nums[i];
            nums[i] = sum;
        }
        return nums;
    }
};