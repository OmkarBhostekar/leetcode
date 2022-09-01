class Solution {
public:
    int rec(vector<int> &nums, int i, int sum, int target, unordered_map<string,int> &m){
        if(i==nums.size()) return sum == target;
        string x = to_string(i) + "_" + to_string(sum);
        if(m.find(x) != m.end()) return m[x];
        int ans = 0;
        ans += rec(nums, i+1, sum+nums[i], target, m);
        ans += rec(nums, i+1, sum-nums[i], target, m);
        return m[x] = ans;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int> m;
        return rec(nums,0,0,target,m);
    }
};