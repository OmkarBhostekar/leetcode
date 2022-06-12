class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int curr = 0, ans = 0, i = 0;
        for (int num : nums) {
            while (seen.find(num) != seen.end()) {
                curr -= nums[i];
                seen.erase(nums[i]);
                i += 1;
            }
            curr += num;
            seen.insert(num);
            ans = max(ans, curr);
        }
        return ans;
    }
};