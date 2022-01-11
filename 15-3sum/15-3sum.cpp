class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans = {};
        if(nums.size() < 3) 
            return ans;
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<nums.size()-2;i++){
            if(i>0 and nums[i] == nums[i-1]) continue;
            int low = i+1;
            int high = nums.size()-1;
            while(low<high){
                int sum = nums[low] + nums[high] + nums[i];
                if(sum<0){
                    low++;
                }else if(sum>0){
                    high--;
                }else{
                    ans.push_back({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
					//to skip duplicates
                    while(low < high && nums[low] == nums[low - 1]) low++;
                    while(low < high && nums[high] == nums[high + 1]) high--;
                }
            }
        }
        return ans;
    }
};