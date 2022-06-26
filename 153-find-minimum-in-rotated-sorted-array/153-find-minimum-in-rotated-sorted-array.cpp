class Solution {
public:
    int findMinLogn(vector<int>& nums, int start, int end){
        if(start == end) return nums[start];
        int mid = start + ((end-start)/2);
        if((mid-1 >=0 && nums[mid-1]>nums[mid]) or (mid==start && nums[mid]<nums[mid+1])) return nums[mid];
        if(nums[start]<nums[mid] && nums[mid]<nums[end])
            return nums[start];
        if(nums[start]>nums[mid] && nums[mid]<nums[end])
            return findMinLogn(nums, start, mid-1);
        else return findMinLogn(nums, mid+1, end);
    }
    
    int findMin(vector<int>& nums) {
        return findMinLogn(nums, 0, nums.size()-1);
    }
};