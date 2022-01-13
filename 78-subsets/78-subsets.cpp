class Solution {
public:
    vector<vector<int>> generateSubSet(vector<int>& nums, int s, int e){
        if(s == e){
            return {{}};
        }
        vector<vector<int>> next = generateSubSet(nums,s+1,e);
        int n = next.size();
        for(int i=0; i<n; i++){
            vector<int> a;
            a.push_back(nums[s]);
            for(int x: next[i]){
                a.push_back(x);
            }
            next.push_back(a);
        }
        return next;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        return generateSubSet(nums, 0, nums.size());;
    }
};