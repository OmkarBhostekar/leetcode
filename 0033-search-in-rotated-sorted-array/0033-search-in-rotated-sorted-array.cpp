class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while(start<=end){
            if(start == end){
                if(target == nums[start]) return start;
                return -1;
            }
            int mid = start + ((end - start)/2);
            if(target == nums[mid]) return mid;
            else if(nums[start] < nums[mid]){
                if(target >= nums[start] and target <= nums[mid])
                    end = mid;
                else
                    start = mid+1;
            }else{
                if(target >= nums[mid+1] and target <= nums[end])
                    start = mid+1;
                else
                    end = mid;
            }
        }
        return -1;
    }
};