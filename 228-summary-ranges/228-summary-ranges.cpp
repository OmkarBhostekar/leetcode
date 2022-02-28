class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        string temp = "";
        vector<string> ans;
        for(int i=0; i<n; i++){
            int j = i;
            while(j+1 < n and nums[j+1] == nums[j]+1) j++;
            if(j > i){
                temp +=  to_string(nums[i]) + "->" + to_string(nums[j]);
            }else{
                temp += to_string(nums[i]);
            }
            ans.push_back(temp);
            temp = "";
            i = j;
        }
        return ans;
    }
};