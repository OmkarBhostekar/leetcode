class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        set<pair<int, int>> s;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(abs(nums[i]-nums[j]) == k){
                    if(s.find({nums[i],nums[j]}) == s.end() and s.find({nums[j],nums[i]}) == s.end()){
                        s.insert({nums[i],nums[j]});
                    }   
                }
            }
        }
        return s.size();
    }
};