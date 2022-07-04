class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size()+2);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i=1;i<adj.size();i++){
            if(adj[i].size() == edges.size())
                return i;
        }
        return -1;
    }
};