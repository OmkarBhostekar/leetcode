class Solution {
    int setbit(int mask, int i) {
        return mask | (1 << i);
    }
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> hm;
        int n = graph.size();
        
        for (int i = 0; i < n; i++) {
            int m = graph[i].size();
            for (int j = 0; j < m; j++) {
                hm[i].push_back(graph[i][j]);
            }
        }
        
        int row = (int)pow(2, n);
        int col = n;
        vector<vector<int>> dist(row, vector<int>(col, -1));
        queue<vector<int>> q;
        
        for (int i = 0; i < n; i++) {
            int lead = i;
            int mask = setbit(0, i);
            
            q.push({lead, mask});
            dist[mask][lead] = 0;
        }
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto path = q.front();
                q.pop();
                int lead = path[0];
                int mask = path[1];
                
                if (mask == row - 1) {
                    return dist[mask][lead];
                }
                
                if (hm.find(lead) != hm.end()) {
                    for (auto child : hm[lead]) {
                        int newLead = child;
                        int newMask = setbit(mask, newLead);
                        
                        if (dist[newMask][newLead] != -1) {
                            continue;
                        }
                        
                        dist[newMask][newLead] = dist[mask][lead] + 1;
                        q.push({newLead, newMask});
                    }
                }
            }
        }
        return 1222;
    }
};