class Solution {
private:
    int time = 0;
    vector<vector<int>> graph;
    vector<int> in, low;
    vector<vector<int>> bridges;
    
    void dfs(int u, int p = -1) {
        in[u] = low[u] = time++;
        for(int v: graph[u]) {
            if(v == p) 
                continue;
            else if(in[v] != -1) {
                low[u] = min(low[u], in[v]);
            } else {
                dfs(v, u);
                if(in[u] < low[v])
                    bridges.push_back(vector<int>({u, v}));
                low[u] = min(low[u], low[v]);
            }
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        in.resize(n, -1);
        low.resize(n, -1);
        
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        dfs(0);
        
        return bridges;
    }
};