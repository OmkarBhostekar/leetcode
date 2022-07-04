class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<bool> &vis, int v){
        vis[v] = true;
        for(auto x: adj[v])
            if(!vis[x]) dfs(adj, vis, x);
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<rooms.size();i++){
            for(auto j: rooms[i]){
                if(i==j) continue;
                adj[i].push_back(j);
            }
        }
        vector<bool> vis(n,false);
        dfs(adj,vis,0);
        for(auto x: vis)
            if(!x) return false;
        return true;
    }
};