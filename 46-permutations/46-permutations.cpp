class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>> &ans, int begin, int n){
        if(begin == n){
            ans.push_back(nums);
            return;
        }
        for(int i=begin;i<n;i++){
            swap(nums[begin],nums[i]);
            backtrack(nums,ans,begin+1,n);
            swap(nums[begin],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(nums, ans, 0, nums.size());
        return ans;
    }
};