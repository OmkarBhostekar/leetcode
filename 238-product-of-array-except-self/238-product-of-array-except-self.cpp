class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long product = 1;
        int zeroes = 0;
        for(int num: nums){
            if(num == 0) {
                zeroes++; 
                continue;
            }
            product *= (long long)num;
        }
        for(int i=0;i<nums.size();i++){
            if(zeroes>1){
                nums[i] = 0;
            }else if(zeroes==1){
                if(nums[i] == 0) nums[i] = product;
                else nums[i] = 0;
            }else nums[i] = product/nums[i];
        }
        return nums;
    }
};