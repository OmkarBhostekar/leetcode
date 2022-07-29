class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int> &vis, int v, vector<int> &ans){
        if(vis[v] == 0 || vis[v] == 1) return vis[v];
        if(vis[v] == -2) return false;
        vis[v] = -2;
        for(auto e: adj[v]){
            if(dfs(adj, vis, e, ans) == 0)
                return vis[v] = 0;
        }
        ans.push_back(v);
        return vis[v] = 1;
    } 
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,-1);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(visited[i] == -1){
                dfs(graph, visited, i, ans);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};