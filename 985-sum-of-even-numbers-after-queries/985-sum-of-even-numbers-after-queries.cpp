class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum = 0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]%2==0)
                sum+=nums[i];
        for(auto q: queries){ // q = valToAdd, idx
            int x = nums[q[1]] + q[0];
            if(nums[q[1]]%2==0){ // already even
                if(x%2==0){
                    sum += (x-nums[q[1]]);
                }else{
                    sum -= nums[q[1]];
                }
            }else{ // wasn't even
                if(x%2==0){
                    sum +=  x;
                }
            }
            nums[q[1]] = x;
            ans.push_back(sum);
        }
        return ans;
    }
};