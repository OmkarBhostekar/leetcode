class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<bool> &vis, stack<int>& topo, int v){
        vis[v] = true;
        for(auto x: adj[v])
            if(!vis[x])
                dfs(adj,vis,topo,x);
        topo.push(v);
    }
    
    void dfs2(vector<vector<int>> &adj, vector<bool> &vis, int v){
        vis[v] = true;
        for(auto x: adj[v])
            if(!vis[x]) dfs2(adj, vis, x);
    }
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> ans;
        for(auto edge: edges)
            adj[edge[0]].push_back(edge[1]);
        stack<int> topo;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs(adj, vis, topo, i);
        }
        for(int i=0;i<n;i++) vis[i] = false;
        while(!topo.empty()){
            int x = topo.top();
            topo.pop();
            if(!vis[x]){
                ans.push_back(x);
                dfs2(adj,vis,x);
            }
        }
        return ans;
    }
};