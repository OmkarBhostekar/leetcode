class Solution {
public:
    bool bfs(int i, vector<vector<int>>& graph, vector<int> &visited){
        queue<int> q;
        q.push(i);
        visited[i] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int it: graph[node]){
                if(visited[it] == -1){
                    visited[it] = 1-visited[node];
                    q.push(it);
                }else if(visited[it] == visited[node]){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,-1);
        for(int i=0;i<n;i++){
            if(visited[i] == -1){
                if(!bfs(i, graph, visited))
                    return false;
            }
        }
        return true;
    }
};