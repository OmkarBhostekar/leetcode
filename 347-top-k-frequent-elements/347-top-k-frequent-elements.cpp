class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        priority_queue<pair<int,int>>  pq;
        vector<int> ans;
        for(int x: nums){
            mpp[x]++;
        }
        for(auto x: mpp){
            pq.push({x.second,x.first});
        }
        for(int i=0;i<k;i++){
            auto x = pq.top();
            pq.pop();
            ans.push_back(x.second);
        }
        return ans;
    }
};