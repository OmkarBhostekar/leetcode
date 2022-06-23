class Solution {
public:
    bool dfs(vector<vector<int>> &adj, vector<int> &v, vector<int> &rs, int i){
        if(!v[i]){
            v[i] = 1;
            rs[i] = 1;
            for(auto x: adj[i]){
                if(!v[x] && dfs(adj,v,rs,x))
                    return true;
                 else if(rs[x]) return true;
            }
        }
        rs[i] = 0;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& pre) {
        sort(pre.begin(), pre.end());
        vector<vector<int>> adj(n);
        for(auto x: pre)
        adj[x[0]].push_back(x[1]);
        vector<int> v(n,0);
        vector<int> rs(n,0);
        for(int i=0;i<n;i++){
            if(!v[i] && dfs(adj, v, rs, i)){
                return false;
            }
        }
        return true;
    }

};