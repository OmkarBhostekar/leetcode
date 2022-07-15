class Solution {
public:
    
    void dfs(vector<vector<int>>& adj, vector<bool> &vis, int i, int n){
        if(i==n || vis[i]) return;
        vis[i] = true;
        for(auto x: adj[i])
            if(!vis[x])
                dfs(adj, vis, x, n);
    }
    
    int findCircleNum(vector<vector<int>>& con) {
        int n = con.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(con[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n,false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(adj,vis,i,n);
            }
        }
        return count;
    }
};