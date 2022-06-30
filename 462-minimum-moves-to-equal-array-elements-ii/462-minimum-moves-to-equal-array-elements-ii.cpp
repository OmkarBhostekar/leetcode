class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid = nums.size()/2;
        int ans=0;
        for(int x: nums){
            ans += abs(x-nums[mid]);
        }
        return ans;
    }
};