class Solution {
public:
    int maximumUnits(vector<vector<int>>& bt, int ts) {
        int ans = 0;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<bt.size();i++){
            pq.push({bt[i][1],i});
        }
        while(ts && !pq.empty()){
            auto top = pq.top();
            pq.pop();
            int x = min(ts,bt[top.second][0]);
            ans += (x*top.first);
            ts -= x;
        }
        return ans;
    }
};