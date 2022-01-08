class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int m = 0;
        for(int i=0; i<n; i++){
            m = max(m,nums[i]+nums[n-1-i]);
        }
        return m;
    }
};