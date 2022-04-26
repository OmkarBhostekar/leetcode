class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        vector<vector<pair<int,int>>> al(p.size());
        for(int i=0;i<p.size()-1;i++){
            for(int j=i+1;j<p.size();j++){
                int dist = abs(p[i][0]-p[j][0]) + abs(p[i][1]-p[j][1]);
                al[i].push_back({dist,j});
                al[j].push_back({dist,i});
            }
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        unordered_set<int> visited;
        pq.push({0,0});
        int res = 0;
        while(visited.size()<p.size()){
            pair<int,int> top = pq.top();
            pq.pop();
            if(visited.find(top.second) != visited.end()) continue;
            res += top.first;
            visited.insert(top.second);
            for(auto x: al[top.second]){
                if(visited.find(x.second) == visited.end())
                    pq.push({x.first,x.second});
            }
        }
        return res;
    }
};