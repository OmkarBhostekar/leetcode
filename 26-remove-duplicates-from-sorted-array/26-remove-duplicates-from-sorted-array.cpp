class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(),count=0,i=0;
        while(i<n){
            int j=i+1;
            while(j<n && nums[i] == nums[j]){
                nums[j] = INT_MAX;
                j++;
                count++;
            }
            i = j;
        }
        sort(nums.begin(),nums.end());
        return nums.size()-count;
    }
};