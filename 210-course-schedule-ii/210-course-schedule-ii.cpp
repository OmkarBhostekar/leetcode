class Solution {
public:
    bool dfs(vector<vector<int>> &adj, vector<int> &v, vector<int> &rs, int i, vector<int> &res){
        if(!v[i]){
            v[i] = 1;
            rs[i] = 1;
            for(auto x: adj[i]){
                if(!v[x] && dfs(adj,v,rs,x, res))
                    return true;
                 else if(rs[x]) return true;
            }
        }
        rs[i] = 0;
        res.push_back(i);
        return false;
    }

    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        sort(pre.begin(), pre.end());
        vector<vector<int>> adj(n);
        for(auto x: pre)
        adj[x[0]].push_back(x[1]);
        vector<int> v(n,0),rs(n,0),res;
        
        for(int i=0;i<n;i++){
            if(!v[i] && dfs(adj, v, rs, i, res)){
                return {};
            }
        }
        return res;
    }
};