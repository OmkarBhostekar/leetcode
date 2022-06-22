class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        if(n<4) return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                
                int low =  j+1, high=n-1;
                while(low<high){
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[low] + (long long)nums[high];
                    if(sum<target)
                        low++;
                    else if(sum>target)
                        high--;
                    else{
                        ans.push_back({nums[i], nums[j], nums[low], nums[high]});
                        low++;
                        high--;
                        while(low<high && nums[low] == nums[low-1]) low++;
                        while(low<high && nums[high] == nums[high+1]) high--;
                    }
                }
                while(j<n-2 && nums[j] == nums[j+1]) j++;
            }
            while(i<n-3 && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};