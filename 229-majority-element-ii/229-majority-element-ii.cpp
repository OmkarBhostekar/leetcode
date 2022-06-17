class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) m[nums[i]]++;
        vector<pair<int,int>> v;
        for(auto x: m) v.push_back({x.second,x.first});
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        int mx = (n/3);
        for(auto x: v){
            if(x.first > mx)
                ans.push_back(x.second);
        }
        return ans;
    }
};