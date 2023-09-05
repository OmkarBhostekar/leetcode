class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& e) {
        vector<vector<int>> adj(n);
        for(auto x: e){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> dp(n);
        vector<int> cnt(n,1);
        function<void(int,int)> dfs1 = [&](int node, int p){
            for(int u: adj[node]){
                if(u != p){
                    dfs1(u,node);
                    cnt[node] += cnt[u];
                    dp[node] += dp[u]+cnt[u];
                }
            }
        };
        dfs1(0,-1);
        function<void(int,int,int)> dfs2 = [&](int node, int p, int pp){
            dp[node] += (n-cnt[node]) + pp;
            int i=0;
            for(int u: adj[node]){
                if(u != p){
                    dfs2(u,node,dp[node] - (dp[u]+cnt[u]));
                    i++;
                }
            }
        };
        dfs2(0,-1,0);
        return dp;
    }
};