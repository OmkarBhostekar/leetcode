class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        set<pair<int,int>> s;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-1; i++){
            int x = nums[i];
            if(binary_search(nums.begin()+i+1, nums.end(), k+x) > 0){
                s.insert({x,x+k});   
            }
        }
        return s.size();
    }
};