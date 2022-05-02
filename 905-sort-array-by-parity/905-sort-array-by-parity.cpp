class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++)
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]%2 == 1){
                    swap(nums[i],nums[j]);
                }
            }
        return nums;
    }
};