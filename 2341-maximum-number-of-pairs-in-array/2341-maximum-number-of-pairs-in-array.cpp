class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int num: nums)
            m[num]++;
        int pairs = 0, left=0;
        for(auto x: m){
            pairs += (x.second/2);
            left += (x.second%2);
        }
        return {pairs,left};
    }
};