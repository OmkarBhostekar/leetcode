class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        map<int,bool> m;
        for(int x: nums) m[x] = 1;
        int ans=0;
        int count=1;
        for(auto x: m){
            if(m[x.first-1]) {
                count++;
            }
            else{
                count = 1;
            }
            ans = max(ans,count);
        }
        return ans;
    }
};